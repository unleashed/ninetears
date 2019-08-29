inherit "/std/room";
/* adaptive prices added by Anirudh, March 1996 
   This is not meant to be exactly a free market system.
   Prices are adjusted to control (limit) the flow of items from 
   the shop into the mud and sales of items to the shop. */
/* Reworked by Hamlet July/August 1995. */
/* New features:
	1)  DOCUMENTATION!  
	2)  A more sensical scaled_value()  (makes more sense to me at least)
	3)  Ability to force-set the price the shop will offer for an item;
	    set_resale_value(), adjust_resale_value(), query_resale_value(),
	    prevent_resale(), and allow_resale()  all added to 
	   /std/basic/misc.c (so, /std/object).
	4)  Stolen items are worth less now.  % modifier and 
	    set_stolen_modifier() to alter that modifier.  Also
	    set_stolen_modifier(), query_stolen_modifier(), and
	    no_sell_if_stolen() in /std/basic/misc.c
	5)  A shop can be sell-only.  The commands "value" and "sell"
	    are turned off for that.  Put sell_only() in setup();
	6)  You can specify a special function in your shop to be run
		ever time something is sold or bought.  call is
		set_sell_func("func") and set_buy_func("func");
		func should look like:  void func(object *stuff);
		Yes, this means that stuff is an ARRAY of items being bought
		or sold.

*/

// Edited 11 SEP 94 by Timion and Taniwha to fix the sell item bug.

/*
 * Original made who knows when.
 * Modified by bil to make the list a lot nicer.
 * Modified by Pinkfish to give shops types and make them send out
 * reps to sell/buy things from other shops.
 */

/* I am not sure whose code is whose any more.  This *is* an extensive
   rewrite, and a lot of it is now mine.  Credits stay, though, since
   I don't know which is which. - Hamlet
*/
/* Note:  rewrite is not done.  A lot of the code is original still.
	    Don't expect that to be true for long (muhahaha)
*/

#include "money_adjust.h"
#include "money.h"
#include "move_failures.h"
#include "shop.h"
#include "armoury.h"
#include "timestuff.h"
#define MIN_PRICE 10

/* our_table is the table for setting sales goals */
object our_storeroom;
mixed our_table;
string storename;
mixed buy_mess, sell_mess, list_mess, value_mess, browse_mess,
open_cond, *other_shops;
/* the variables for item sales data and adjust time, Anirudh */
mapping market_data, race_prefs;
int last_changed_price,handled_since_last;
int no_price_reduce;

int amount_sold,
amount_bought;
string shop_type;
int stolen_modifier;  /* This will be a percent value */
int only_sell = 0;
string sell_func, buy_func;

void set_store_room(mixed ob);
string query_name(object ob);
string query_short(object ob);
int check_inv(object ob, string str);
string shop_list(mixed arr, int detail);
void do_buy(object *ob, int cost, object pl);
string shop_parse(string str, mixed ob, object client, string money,
  string extra);
void do_parse(mixed arr, mixed ob, object client, string money,
  string extra);
/* adaptive price functions, Anirudh */
int no_lower_price(int arg) { no_price_reduce = arg; }
int do_weight_min(int amt, int mass, int material, int sellbuy);
int do_cha_adjust(int amt, int cha, int updown);
int do_race_adjust(int amt, string race, int updown);
int set_race_pref(string race, int race_perc);
int query_multiplier(object ob);
void add_bought(object ob);
void add_sold(object ob);
void add_new_item(object ob,string str);
void check_adjust_prices();
void check_shop_table();
void check_cloned_items();
void adjust_prices();
void reset_market();
string query_storename() { return storename; }


void create() {
    market_data = ([ ]);
    race_prefs = ([ ]);
    seteuid((string)"/secure/master"->
      creator_file(file_name(this_object())));
    restore_object(file_name(this_object()));
    buy_mess = ({ "You buy $ob$ for $money$.\n",
      "$client$ buys $ob$.\n" });
    sell_mess = ({ "You sell $ob$ for $money$.\n",
      "$client$ sells $ob$.\n" });
    list_mess = "$extra$";
    value_mess = "The $ob$ is valued at $money$.\n";
    browse_mess = "The $ob$ costs $money$, it looks like:\n$extra$";
    open_cond = 1;
    other_shops = ({ });
    shop_type = "general";
    stolen_modifier = 33;  /* 33% of normal value */
    ::create();
}

/* These make spiffy messages for various actions. */
void set_sell_message(mixed str) { sell_mess = str; }
void set_buy_message(mixed str) { buy_mess = str; }
void set_value_message(mixed str) { value_mess = str; }
void set_browse_message(mixed str) { browse_mess = str; }
void set_list_message(mixed str) { list_mess = str; }

void set_open_condition(mixed str) { open_cond = str; }

mixed query_sell_mess() { return sell_mess; }
mixed query_list_mess() { return list_mess; }
mixed query_value_mess() { return value_mess; }
mixed query_buy_mess() { return buy_mess; }
mixed query_browse_mess() { return browse_mess; }

/* These initialize sell_func and buy_func, which are special functions
   that can be set to run when something is bought or sold.
*/
void set_sell_func(string str) {  sell_func = str; }
void set_buy_func(string str) { buy_func = str; }

mixed query_open_condition() { return open_cond; }

object check_storeroom()
{
    if(stringp(our_storeroom) || !our_storeroom)
	set_store_room(storename);
    return our_storeroom;

}

/* This is whether the shop is open or not.  open_cond can be
   an int (true/false). Or a string, in which case it 'points'
   to a function in the current object to run.  OR, it can be
   an array.  ({ "object/name", "function_name" }) where it runs
   "object/name"->function_name() to determine whether the shop is
   open.
*/
int test_open() {
    if (stringp(open_cond))
	return (int)call_other(this_object(), open_cond);
    if (intp(open_cond))
	return open_cond;
    return (int)call_other(open_cond[0], open_cond[1]);
}

int sell_only() {  only_sell = 1; return 1; }

int set_race_pref(string race, int race_perc) {
    int i;
    if(!m_sizeof(race_prefs)) race_prefs = ([ ]);
    if(race_perc != -1 && race_perc < 100) race_perc = 100;
    if(race == "good") {
	for(i=0;i<sizeof(GOOD_RACES);i++)
	    race_prefs[GOOD_RACES[i]] = race_perc;
	return race_perc;
    }
    if(race == "neutral") {
	for(i=0;i<sizeof(NEUTRAL_RACES);i++)
	    race_prefs[NEUTRAL_RACES[i]] = race_perc;
	return race_perc;
    }
    if(race == "evil") {
	for(i=0;i<sizeof(EVIL_RACES);i++)
	    race_prefs[EVIL_RACES[i]] = race_perc;
	return race_perc;
    }
    race_prefs[race] = race_perc;
    return race_perc;
}

void init() {
    ::init();
    add_action("sell", "sell");
    add_action("buy", "buy");
    add_action("list", "list");
    add_action("browse", "browse");
    add_action("value", "value");
}

/* This determines how much the shopkeeper will offer for an item, according
   to its value.  It only gets called if set_no_resell() has not been called
   and resale_value has not been hand-set to something.
*/
int scaled_value(int n)
{
    int *prates;
    int i, tot;

    tot = 0;
    prates = PAY_RATES;
    for(i=0;( (i<sizeof(prates)) && (n > prates[i]) );i+=2);

    if(i>0)
	i-=2;/* prates[i] is now the rate-increment directly below the value. */

    tot = (n - prates[i]) * ((prates[i+2] / prates[i+3]) - 
      (prates[i] / prates[i+1]));
    tot /= (prates[i+2] - prates[i]);
    tot += (prates[i] / prates[i+1]);

    /* For those curious, we just defined a line segment.  Basically, we
	 used  y - y1 = m(x - x1).  And found the y value for x = n.
	 Read shop.h for better explanation.
    */

    return tot;
}

int set_stolen_modifier(int amt) { 
    if(amt > 100)
	amt = 100;
    if(amt < 0)
	amt = 0;

    stolen_modifier = amt;

    return amt;
}

/* This checks the player to make sure they have the item. 
   I *think* this is a paranoia check, but I'll leave it.
*/
int check_inv(object thing, string str)
{
    int i;
    object *inv = find_match(str,this_player());

    for(i =0; i < sizeof(inv); i++) {
	if(inv[i] == thing) return(1);
    }

    return(0);
}

int sell(string str) {
    object *obs, *selling, *cannot;
    mixed *m_array;
    int i, j, no, amt, material, mass, value, total_amt;
    string s;

    if (!test_open())
	return 0;

    if(only_sell) {
	tell_object(this_player(),"This shop does not buy merchandise.\n");
	return 1;
    }

    if (!str || str == "") {
	notify_fail("Usage: sell <objects>\n");
	return 0;
    }
    obs = find_match(str, this_player());
    if (!sizeof(obs)) {
	notify_fail("Nothing to sell.\n");
	return 0;
    }
    if(sizeof(obs) > MAX_OBS) {
	write("The shopkeeper can't cope with all those objects.\n");
	obs = obs[0..MAX_OBS - 1];
    }
    check_storeroom();
    selling = cannot = ({ });
    for (i=0;i<sizeof(obs);i++) {
	if( (obs[i]->query_value() > 0) && !obs[i]->do_not_sell() &&
	  (obs[i]->query_resale_value() != -1) && 
	  ((obs[i]->query_stolen_modifier() != -1) || 
	    !obs[i]->query_property("stolen")) && !obs[i]->query_in_use()) {
	    /* O.K. this SHOULD check to see if the item IS in the
	       inventory
	       before we move it */
	    if(check_inv(obs[i],str)) {
		if (obs[i]->move(our_storeroom)) {
		    if (obs[i]->short())
			cannot += ({ obs[i] });
		    continue;
		}
		/* the call other (buried) in the below is so that we can update 
		   /std/shop and have all the shops prices fall in line
		   consistently */
		amt = obs[i]->query_resale_value();
		if(!amt) {
		    amt = (int)"/std/shop"->scaled_value((int)obs[i]->query_value());
		    if(amt > MAX_AMOUNT)
			amt = MAX_AMOUNT;
		}

		/* Let's not let something sell back for more than it was bought
		   for */
		if(amt > obs[i]->query_value())
		    amt = obs[i]->query_value();

		/* "hot" goods lose value!  */      
		if(obs[i]->query_property("stolen")) {
		    if(obs[i]->query_stolen_modifier() == 0)
			amt = amt * stolen_modifier / 100;
		    else
			amt = amt * obs[i]->query_stolen_modifier() / 100;
		}
		/* Adjusts price by item's adaptive multiplier (in 1/10 %) */
           /*Adjust by mudwide scale factor */
                amt=amt*MONEY_TRACKER->query_adj_fact(SBFLAG)/1000;
		amt=amt*query_multiplier(obs[i])/1000;
		amt = do_weight_min(amt,obs[i]->query_weight(),
		  obs[i]->query_material(),1);
		amt = do_cha_adjust(amt,this_player()->query_cha(),1);
		if((amt = do_race_adjust(amt,this_player()->query_race(),1))==
		  -101) { notify_fail("This shop refuses to deal with your "+
		      "race.\n");
		    amt = 0;
		    return 0;
		}
		/* Counts how many of each item the shop buys */
		if(!(this_player()->query_creator()) &&
		  strsrch(this_player()->query_name(),"test") == -1)
		    add_bought(obs[i]);
		total_amt += amt;
		selling += ({ obs[i] });
		obs[i]->being_sold();
	    }else if (obs[i]->short())
		cannot += ({ obs[i] });
	    /* end of test if exists, not that this DOESN'T do the cannot that it should
	    */
	}
	else if (obs[i]->short())
	    cannot += ({ obs[i] });
    }
    if (!sizeof(selling)) {
	if (sizeof(cannot))
	    notify_fail("You cannot sell "+query_multiple_short(cannot)+", maybe you are holding or wearing it, or just don't have one.\n");
	else
	    notify_fail("Nothing to sell.\n");
	return 0;
    }
    amount_sold += total_amt;
    m_array = (mixed *)MONEY_HAND->create_money_array(total_amt);
    this_player()->adjust_money(m_array);
    if (sizeof(cannot))
	write("You cannot sell "+query_multiple_short(cannot)+", maybe you are wearing or holding it, or just don't have one.\n");
    do_parse(sell_mess, selling, this_player(),
      (string)MONEY_HAND->money_string(m_array), "");
    if(sell_func)  call_other(this_object(),sell_func,selling,total_amt);
    return 1;
}

int buy(string str) {
    int i, amt, material, mass, ob_amt, total_cost, high_cost_flag;
    object *obs, *to_buy, *cannot, *too_much;
    string s;

    if (!test_open())
	return 0;

    if (!str || str == "") {
	notify_fail("Usage: buy <objects>\n");
	return 0;
    }
    check_storeroom();
    obs = find_match(str, our_storeroom);
    if (!sizeof(obs)) {
	notify_fail("Cannot find "+str+".\n");
	return 0;
    }
    if(sizeof(obs) > MAX_OBS) {
	write("The shopkeeper can't cope with all those objects.\n");
	obs = obs[0..MAX_OBS-1];
    }
    to_buy = too_much = cannot = ({ });
    amt = (int)this_player()->query_value();
    while (i<sizeof(obs)) {
	/* adjusts price by adaptive multiplier of object */
      high_cost_flag = 0;
      if((ob_amt=(obs[i]->query_value()))>100000) {
         high_cost_flag = 1;
         ob_amt /= 100;
      }
       ob_amt=ob_amt*MONEY_TRACKER->
            query_adj_fact(SSFLAG)/1000;
         ob_amt=ob_amt*query_multiplier(obs[i])/1000;
/*
if(ob_amt>2000000) {
       ob_amt=0;
         secure_log_file("ani",this_player()->query_name()+" "+ctime(time())+
     "\n");
}
*/
	ob_amt = do_weight_min(ob_amt,obs[i]->query_weight(),
	  obs[i]->query_material(),0);
	ob_amt = do_cha_adjust(ob_amt,this_player()->query_cha(),0);
	if((ob_amt = do_race_adjust(ob_amt,this_player()->query_race(),0))==
	  -101) { notify_fail("This shop refuses to deal with your "+
	      "race.\n");
	    return 0;
	}
     if(obs[i]->query_property("playersetvalue")){
        high_cost_flag = 0;
        ob_amt = obs[i]->query_property("playersetvalue");
        // voided my hard work, better have a good reason
        secure_log_file("SHOPS",file_name(this_object())+" "+
                         file_name(obs[i])+" player set value\n");
     }
     if(high_cost_flag) ob_amt *= 100;
        if (ob_amt < 1) {
           ob_amt = 1;
         secure_log_file("SHOPS",file_name(this_object())+" "+
            file_name(obs[i])+" 0 value, "
               +this_player()->query_name()+"\n");
        }
	if (ob_amt > amt) {
	    if (obs[i]->short())
		too_much += ({ obs[i] });
	    obs = delete(obs, i, 1);
	    continue;
	}
	if (obs[i]->move(this_player())) {
	    if (obs[i]->short())
		cannot += ({ obs[i] });
	    i++;
	    continue;
	}
	obs[i]->move(our_storeroom);
	amt -= ob_amt;
	total_cost += ob_amt;
	to_buy += ({ obs[i] });
	i++;
    }
    amount_bought += total_cost;
    s = "";
    if (sizeof(cannot))
	s += "You cannot pick up "+query_multiple_short(cannot)+".\n";
    if (sizeof(too_much))
	s += capitalize(query_multiple_short(too_much))+" costs too much.\n";
    if(!sizeof(to_buy)) {
	if(s != "")
	    notify_fail(s);
	else
	    notify_fail("Nothing to buy.\n");
	return 0;
    } else {
	write(s);
    }
    do_buy(to_buy, total_cost, this_player());
    if(buy_func)  call_other(this_object(),buy_func,to_buy,total_cost);
    return 1;
}

void do_buy(object *obs, int cost, object pl) {
    int i;
    mixed fish;

    for (i=0;i<sizeof(obs);i++) {
	/* counts how many of each item the shop sells */
	if(!(this_player()->query_creator()) &&
	  strsrch(this_player()->query_name(),"test") == -1)
	    add_sold(obs[i]);
       obs[i]->remove_property("playersetvalue");
	obs[i]->move(pl);
    }
    pl->pay_money(fish = (int)MONEY_HAND->create_money_array(cost));
    do_parse(buy_mess, obs, pl,
      (string)MONEY_HAND->money_string(fish), "");
}
int list(string str) {

    if (!test_open())
	return 0;
    check_storeroom();    
    if(!our_storeroom)
    {
	notify_fail("The storeroom has been damaged, the shop is closed for now.\n");
	return 0;
    }
    if (!str || str == "" || str == "all") {
	do_parse(list_mess, this_object(), this_player(), "",
	  shop_list(all_inventory(our_storeroom), 0));
	return 1;
    }
    do_parse(list_mess, this_object(), this_player(), "",
      shop_list(find_match(str, our_storeroom), 1));
    return 1;
}

int browse(string str) {
    object *obs;
    int i, ob_amt, mass, material, high_cost_flag;

    if (!test_open())
	return 0;
    if (!str || str == "") {
	notify_fail("Usage: browse <objects>\n");
	return 0;
    }
    check_storeroom();
    obs = find_match(str, our_storeroom);
    if (!sizeof(obs)) {
	notify_fail("Cannot find "+str+".\n");
	return 0;
    }
    for (i=0;i<sizeof(obs);i++) {
      high_cost_flag = 0;
      if((ob_amt=(obs[i]->query_value()))>100000) {
         high_cost_flag = 1;
         ob_amt /= 100;
      }
       ob_amt=ob_amt*MONEY_TRACKER->
            query_adj_fact(SSFLAG)/1000;
         ob_amt=ob_amt*query_multiplier(obs[i])/1000;
/*
if(ob_amt>2000000) {
       ob_amt=0;
}
*/
	ob_amt = do_weight_min(ob_amt,obs[i]->query_weight(),
	  obs[i]->query_material(),0);
	ob_amt = do_cha_adjust(ob_amt,this_player()->query_cha(),0);
	if((ob_amt = do_race_adjust(ob_amt,this_player()->query_race(),0))==
	  -101) { notify_fail("This shop refuses to deal with your "+
	      "race.\n");
	    return 0;
	}
     if(obs[i]->query_property("playersetvalue")){
        high_cost_flag = 0;
        ob_amt = obs[i]->query_property("playersetvalue");
     }
     if(high_cost_flag) ob_amt *= 100;
	if (ob_amt < 1) ob_amt = 1;
	do_parse(browse_mess, obs[i], this_player(),
	  (string)MONEY_HAND->money_value_string(ob_amt),
	  (string)obs[i]->long());
    }
    /*
	write("You look at "+obs[i]->short()+" it costs "+
		 MONEY_HAND->money_string(obs[i]->query_money_array())+"\n"+
		obs[i]->long());
     */
    return 1;
}
int value(string str) {
    object *obs;
    int i, val, mass, material;

    if (!test_open())
	return 0;

    if(only_sell) {
	tell_object(this_player(),"This shop cannot appraise your goods.\n");
	return 1;
    }

    if (!str || str =="") {
	notify_fail("Usage: value <object>\n");
	return 0;
    }

    obs = find_match(str, this_player());
    if (!sizeof(obs)) {
	notify_fail("Cannot find "+str+".\n");
	return 0;
    }
    for (i=0;i<sizeof(obs);i++) {
	/* the call other is so that we can change the PAY_RATES array, and 
	     then just update /std/shop to immediately and consistently effect 
	     all shops */
	val = obs[i]->query_resale_value();

	if(!val) {
	    val = (int)"/std/shop"->scaled_value((int)obs[i]->query_value());
	    if (val > MAX_AMOUNT)
		val = MAX_AMOUNT;
	}

	if(val > obs[i]->query_value())
	    val = obs[i]->query_value();

	/* "hot" goods lose value!  */      
	if(obs[i]->query_property("stolen")) {
	    if(obs[i]->query_stolen_modifier() == 0)
		val = val * stolen_modifier / 100;
	    else
		val = val * obs[i]->query_stolen_modifier() / 100;
	}
	/* adjust price offered by the adaptive multiplier of the item */
                val=val*MONEY_TRACKER->query_adj_fact(SBFLAG)/1000;
	val = val*query_multiplier(obs[i])/1000;
	val = do_weight_min(val,obs[i]->query_weight(),
	  obs[i]->query_material(),1);
	val = do_cha_adjust(val,this_player()->query_cha(),1);
	if((val = do_race_adjust(val,this_player()->query_race(),1))==
	  -101) { notify_fail("This shop refuses to deal with your "+
	      "race.\n");
	    return 0;
	}
	do_parse(value_mess, obs[i], this_player(),
	  (string)MONEY_HAND->money_value_string(val),
	  (string)(obs[i]->do_not_sell() || 
	    (obs[i]->query_resale_value() == -1)) );
    }
    return 1;
}

string shop_list(mixed arr, int detail) {
    mapping inv, costs;
    object *list;
    string s, mon, *shorts, *vals;
    int i, j, mass, material, ob_amt, high_cost_flag;
    mixed ind;

    if (pointerp(arr))
	list = arr;
    else
	list = all_inventory(this_object()); 
    /* only keep track of things with shorts ;) */
    inv = ([ ]);
    for (i=0; i<sizeof(list); i++) {
	s = (string)list[i]->short();
	if (!s || !list[i]->query_value())
	    continue;
	if(!stringp(s))
	    s = "get a creator for this one!";
	if (inv[s])
	    inv[s] += ({ list[i] });
	else
	    inv[s] = ({ list[i] });
    }
    /* ok print it */
    s = "";
    shorts = m_indices(inv);
    if(!sizeof(shorts)) {
	if(detail)
	    return "The shop is all out of what you wanted.\n";
	else
	    return "The shop is totally out of stock.\n";
    }
    s = "You find on offer:\n";
    for (i=0; i<sizeof(shorts); i++) {
	ind = inv[shorts[i]];
	switch(sizeof(ind)) {
	case 1:
	    s += "Our very last " + shorts[i];
	    break;
	case 2..5:
	    s += capitalize(query_num(sizeof(ind), 0) + " " +
	      (string)ind[0]->query_plural());
	    break;
	default:
	    if(detail)
		s += capitalize(query_num(sizeof(ind), 0) + " " +
		  (string)ind[0]->query_plural());
	    else
		s += "A large selection of " +
		(string)ind[0]->query_plural();
	}
	if(detail) {
	    costs = ([ ]);
	    for(j=0;j<sizeof(ind);j++) {
		/* lists price after multiplier is applied */
      high_cost_flag = 0;
      if((ob_amt=(ind[i]->query_value()))>100000) {
         high_cost_flag = 1;
         ob_amt /= 100;
      }
       ob_amt=ob_amt*MONEY_TRACKER->
            query_adj_fact(SSFLAG)/1000;
         ob_amt=ob_amt*query_multiplier(ind[i])/1000;
		ob_amt = do_weight_min(ob_amt,ind[i]->query_weight(),
		  ind[i]->query_material(),0);
		ob_amt = do_cha_adjust(ob_amt,this_player()->query_cha(),0);
		if((ob_amt = do_race_adjust(ob_amt,this_player()->query_race(),0))==
		  -101) { notify_fail("This shop refuses to deal with your "+
		      "race.\n");
		    return 0;
		}
     if(ind[i]->query_property("playersetvalue")){
        high_cost_flag = 0;
        ob_amt = ind[i]->query_property("playersetvalue");
     }
     if(high_cost_flag) ob_amt *= 100;
		if (ob_amt < 1) ob_amt = 1;
		mon=(string)MONEY_HAND->money_value_string(ob_amt);
		if(!costs[mon])
		    costs[mon] = ({ "" + (j + 1) });
		else
		    costs[mon] += ({ "" + (j + 1) });
	    }
	    if(m_sizeof(costs) == 1) {
		s += " for " + m_indices(costs)[0];
		if(sizeof(m_values(costs)[0]) > 1)
		    s += " each.\n";
		else
		    s += ".\n";
	    } else {
		s += ":-\n";
		vals = m_indices(costs);
		for(j=0;j<sizeof(vals);j++)
		    s += "  [#" + implode(costs[vals[j]], ",") + "] for " + vals[j] +
		    ".\n";
	    }
	} else {
	    s += ".\n";
	}
    }
    return s;
}
void set_store_room(mixed ob) {
    if (stringp(ob)) {
	storename = ob;
	our_storeroom = find_object(ob);
	if (!our_storeroom)
	    call_other(ob, "??");
	our_storeroom = find_object(ob);
    }
    else if(objectp(ob))
    {
	storename = explode(file_name(ob),"#")[0];
	our_storeroom = ob;
    }   
if(our_table && our_storeroom) check_shop_table();
}
object query_store_room() { return our_storeroom; }

void do_parse(mixed arr, mixed ob, object client, string money,
  string extra) {
    if (stringp(arr))
	write(shop_parse(arr, ob, client, money, extra));
    else {
	write(shop_parse(arr[0], ob, client, money, extra));
	say(shop_parse(arr[1], ob, client, money, extra));
    }
}
string shop_parse(string str, mixed ob, object client, string money,
  string extra) {
    string s1, s2, s3, rest;

    rest = "";
    while(sscanf(str,"%s$%s$%s", s1, s2, s3) == 3)
	switch (s2) {
    case "ob" :
	if (pointerp(ob))
	    str = s1+query_multiple_short(ob)+s3;
	else
	    str = s1+ob->short()+s3;
	break;
    case "client" :
	str = s1+client->query_cap_name()+s3;
	break;
    case "extra" :
	str = s1+extra+s3;
	break;
    case "money" :
	str = s1+money+s3;
	break;
    default :
	rest = s1+"$"+s2+"$";
	str = s3;
	break;
    }
    return rest+str;
}


/*
 * The shop types are:
 *  Jewelry
 *  Armory
  *  Magic
 *  General
 */
object *query_stock(string type) {
    mixed *obs;
    int i;
    check_storeroom();
    obs = unique_array(all_inventory(our_storeroom), "query_shop_type");
    for (i=0;i<sizeof(obs);i++)
	if ((string)obs[i][0]->query_shop_type() == type)
	    return obs[i];
    return ({ });
}

mixed *stats() {
    return ::stats() + ({
      ({ "total sold", amount_sold }),
      ({ "total bought", amount_bought }),
    });
}
string query_shop_type() { return shop_type; }
void set_shop_type(string ty) { shop_type = ty; }

/* The new adaptive pricing functions, keep track of buys and sells,
   return multipliers, figure out when and how to change multipliers,
   save and recall the shop's data */
int do_race_adjust(int amt, string race,int updown) {
    int temp;
    if(!m_sizeof(race_prefs)) race_prefs = ([ ]);
    if(!race_prefs[race]) return amt;
    if(race_prefs[race] == -1) return -101;
    if(updown) {
	temp = amt*100/race_prefs[race]+1;
	if(temp > amt) return amt;
	return temp;
    }
    else {
	temp = amt*race_prefs[race]/100-1;
	if(temp < amt) return amt;
	return temp;
    }
    return amt;
}

int do_weight_min(int amt,int mass, int material, int buysell) {
    if(buysell) {
	if (material == 2 && amt < mass) amt = mass;
	else if (material == 1 && amt < mass/4) amt = mass/4;
	else if (material == 3 && amt < mass/7) amt = mass/7;
	else if (amt < mass/10) amt = mass/10;
    }
    else {
	if (material == 2 && amt < mass*3/2) amt=mass*3/2;
	else if (material == 1 && amt < mass*3/8 ) amt=mass*3/8;
	else if (material == 3 && amt < mass*3/14) amt=mass*3/14;
	else if (amt < mass*3/20) amt = mass*3/20;
    }
    return amt;
}

int do_cha_adjust(int amt, int cha, int updown) {
    int temp;
    if(!cha) return amt;
    if(cha > 19) cha = 19;
    if(cha > AVG_CHA) {
	temp = 10*(cha - AVG_CHA)*CHA_AD/(18-AVG_CHA);
	if(updown) {
	    temp = amt*(1000+temp)/1000-1;
	    if(temp < amt) return amt;
	}
	else {
	    temp = amt*1000/(1000+temp)+1;
	    if(temp > amt) return amt;
	}
	return temp;
    }
    if(cha < AVG_CHA) {
	temp = 10*(AVG_CHA-cha)*CHA_AD/(AVG_CHA-3);
	if(updown) {
	    temp = amt*1000/(1000+temp)+1;
	    if(temp > amt) return amt;
	}
	else {
	    temp = amt*(1000+temp)/1000-1;
	    if(temp < amt) return amt;
	}
	return temp;
    }
    return amt;
}

int query_multiplier(object ob) {
    int i;
    string item_path,*exper; 
    if (ob->query_property("fixed_price")) {
       secure_log_file("SHOPS",file_name(this_object())+" "+file_name(ob)+
                     " fixed price\n");
       return 1000;
    }
    if (!m_sizeof(market_data)) restore_object(file_name(this_object()),1);
    exper = explode(file_name(ob),"#");
    item_path = exper[0];
    if(!mappingp(market_data))
    {
	market_data = ([ ]);
	return 1000;
    }
    if (market_data[item_path]) {
	if(only_sell && market_data[item_path][4] < 1000 &&
	  no_price_reduce) {
	    market_data[item_path][4] = 1000;
         secure_log_file("SHOPS",file_name(this_object())+" no reduce\n");
	}
	return market_data[item_path][4];
    }
    else 
	return 1000;
} 

/* note:  this is the function when the SHOP buys something */
void add_bought(object ob) {
    int i;
    string item_path;
    if (!m_sizeof(market_data)) 
	restore_object(file_name(this_object()),1);
    item_path = explode(file_name(ob),"#")[0];
    if (market_data[item_path])
	market_data[item_path][1]++;
    else {
	add_new_item(ob,item_path);
	if (market_data[item_path])
	    market_data[item_path][1]++;
    }
    handled_since_last++;
    check_adjust_prices();
    if (m_sizeof(market_data))
	save_object(file_name(this_object()));
}

/* and this is when the SHOP sells something */
void add_sold(object ob) {
    int i;
    string item_path;
    if (!m_sizeof(market_data)) restore_object(file_name(this_object()),1);
    if(!m_sizeof(market_data)) return ; // Taniwha, no shop table.
    item_path = explode(file_name(ob),"#")[0];
    if (market_data[item_path])
	market_data[item_path][2]++;
    else {
	add_new_item(ob,item_path);
	if (market_data[item_path])
	    market_data[item_path][2]++;
    }
    handled_since_last++;
    if (market_data[item_path][3] && market_data[item_path][2] >=
      3*market_data[item_path][3])
	adjust_prices();
    else
	check_adjust_prices();
    if (m_sizeof(market_data))
	save_object(file_name(this_object()));
}

void add_new_item(object ob, string item_path) {
    check_cloned_items();
    if (!market_data[item_path]) {
	market_data[item_path] = ({ ob->query_value(),0,0,0,1000,0 });
    }
}

void set_item_table(mixed ob) {
    if (stringp(ob)) {
	our_table = find_object(ob);
	if (!our_table)
	    call_other(ob, "??");
	our_table = find_object(ob);
    }
    our_table = ob;
   if(our_storeroom && our_table) check_shop_table();
}
object query_item_table() { return our_table; }

/* this will put the numbers in the table into market_data */
void check_shop_table() {
    int i, clone_flag;
    string *item_paths,ite;
    mapping shelves;
    if (!m_sizeof(market_data)) restore_object(file_name(this_object()),1);
    shelves = our_table->query_shelves();
    if(shelves) // Taniwha 1996
	item_paths = m_indices(shelves);
    if(sizeof(our_storeroom->query_room_clones())) clone_flag = 1;
    for (i=0;i<sizeof(item_paths);i++) {
	ite = 0;
	ite = explode(item_paths[i],".c")[0];
	if (!market_data[ite]) add_new_item(load_object(ite),ite);
	market_data[ite][3]=shelves[item_paths[i]][0];
	if (!clone_flag)
	    our_storeroom->add_clone(ite,shelves[item_paths[i]][1]);
    }
    if (!clone_flag)
	our_storeroom->reset();
    if (m_sizeof(market_data))
	save_object(file_name(this_object()));
}

void check_cloned_items() {
    int i,count,price;
    object dummy;
    mixed *cloned_items;
   check_storeroom();
    cloned_items = our_storeroom->query_room_clones();
    for (i=0;i<sizeof(cloned_items);i++) {
	if (!cloned_items[i] || objectp(cloned_items[i])) {
	    count++;
	}
	else {
	    dummy = clone_object(cloned_items[i]);    
	    if (dummy) {
		cloned_items[i] = explode(cloned_items[i],".c")[0];
		price = dummy->query_value();
		if (!market_data[cloned_items[i]] || 
		  market_data[cloned_items[i]][0]!=price) {
		    if (price < 10000) market_data[cloned_items[i]] = 
			({ price,0,0,count*3,1000,1 });        
		    else market_data[cloned_items[i]] =
			({ price,0,0,count*2,1000,1 });
		}
		dummy->dest_me();
	    }
	    count = 0;
	}
    }
}

void check_adjust_prices() {
    int timelapsed = TIMEKEEPER->query_running_time()-
    last_changed_price;
    if (timelapsed <= 0 || last_changed_price == 0) {
	reset_market();
    }
    else if ( handled_since_last > 300 || timelapsed > BASE_WEEK) {
	adjust_prices();
    }
}

void adjust_prices() {
    string *item_paths,ite;        
    int i,goaldif,changemult,goal,timelapsed,devisor;
    if(!m_sizeof(market_data)) restore_object(file_name(this_object()),1);
    timelapsed = TIMEKEEPER->query_running_time()-last_changed_price;
    /* don't want to overflow maxint here (percent of a week here) */
    if (timelapsed < 20000000) {
	timelapsed = timelapsed*100/BASE_WEEK;
    }
    else timelapsed = timelapsed*10/BASE_WEEK*10;
    item_paths = m_indices(market_data);
    for (i=0;i<sizeof(item_paths);i++) {
	ite = item_paths[i];
	if (market_data[ite][5]) {
	    market_data[ite][5] = 0;
	    market_data[ite][1]=market_data[ite][2]=0;
	    continue;
	}
	/* going to deal in 100ths of items... */
	goal = market_data[ite][3]*timelapsed;
	goaldif=100*(market_data[ite][2]-market_data[ite][1])-goal;
	if (goal) {
	    if (goal > 100*market_data[ite][2])
		changemult = goaldif*goaldif/goal;
	    else
	    {
		// Taniwha /0 insanities
		if(market_data[ite][2] == 0) changemult = 1;
		else changemult = goaldif*goaldif/100/market_data[ite][2];
	    }
	    if (goaldif > 0) {
		if (changemult > 2000) changemult = 2000;
		market_data[ite][4] = market_data[ite][4]*
		(1000+changemult)/1000;
	    }
	    if (goaldif < 0) { 
		if (changemult > 1000) changemult = 1000;
		market_data[ite][4] = market_data[ite][4]*
		1000/(1000+changemult);
		if (market_data[ite][4] < MIN_PRICE)
		    market_data[ite][4]=MIN_PRICE;
	    }
	    market_data[ite][1]=market_data[ite][2]=0;
	}
	else {
	    goaldif+=100;
	    devisor = 2*market_data[ite][2]+market_data[ite][1];
	    if (!devisor) devisor = 10;
	    changemult = goaldif*goaldif/(100*devisor);
	    if (goaldif > 0) {
		market_data[ite][4] = market_data[ite][4]*11/10;
		if (market_data[ite][4] > 1000)
		    market_data[ite][4] = 1000;
	    }
	    if (goaldif < 0) {
		if (changemult > 2000) changemult = 2000;
		market_data[ite][4] = market_data[ite][4]*
		1000/(1000+changemult);
		if (market_data[ite][4]<MIN_PRICE)
		    market_data[ite][4]=MIN_PRICE;
	    }
	    market_data[ite][1]=market_data[ite][2]=0;
	    if (!market_data[ite][3] && market_data[ite][4] == 1000)
		market_data = m_delete(market_data,ite);
	}
    }        
    last_changed_price = TIMEKEEPER->query_running_time();
    handled_since_last = 0;
    if (m_sizeof(market_data))
	save_object(file_name(this_object()));
}
mapping query_market_data() {
    return market_data;
}

void reset_market() {
    string *item_paths,ite;
    int i;
    if (!m_sizeof(market_data)) restore_object(file_name(this_object()),1);
    item_paths = m_indices(market_data);
    for (i=0;i<sizeof(item_paths);i++) {
	ite = item_paths[i];
	market_data[ite][5] = market_data[ite][1]=
	market_data[ite][2]=0;
    }
    last_changed_price = TIMEKEEPER->query_running_time();
    handled_since_last = 0;
    if (m_sizeof(market_data)) save_object(file_name(this_object()));
}
int set_md_value(string which_item,int which_one,int new_value) {
    if (!m_sizeof(market_data)) restore_object(file_name(this_object()),1);
    if(market_data[which_item]) {
	market_data[which_item][which_one] = new_value;
    }
    if (m_sizeof(market_data)) save_object(file_name(this_object()));
    if(market_data[which_item])
	return market_data[which_item][which_one];
    else return -101;
}
/* clean up the storeroom when we die */
void dest_me()
{
    if(our_storeroom) our_storeroom->dest_me();
    ::dest_me();
}       

