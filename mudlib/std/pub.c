inherit "std/room";
#define AUTOMATIC 1
#define BAR_TRACKER "/d/aprior/guilds/bard/tools/bar_tracker.c"
#include "pub.h"
#include "money.h"
#include "drinks.h"
#include "timestuff.h"
#include "money_adjust.h"
 
static mapping menu_items, menu_aliases;
static string menu_header;
int display_headings, last_adjust, pts_healed, gross_inc, last_sign;
static object menu_object;
mapping prices_used, *best_prices, race_prefs;

/* Taniwha 1995 , block clean_up() from removing items
 *
 */
int clean_up(int flag) { return 1; }
int clean_up_room(int flag) {  return 1; }

string read();
int do_cha_adjust(int amt,int cha);
int do_race_adjust(int amt, string race);
int set_race_pref(string race, int race_perc);
void check_adjust_prices();
void adjust_prices();
mapping query_prices_used() { return prices_used; }
int *query_data() { return ({ last_adjust,pts_healed,gross_inc});}

void create() {
  best_prices = ({ });
  prices_used = ([ ]);
  seteuid((string)"/secure/master"->creator_file(file_name(this_object())));
  restore_object(file_name(this_object()),1);
  menu_items = ([ ]);
  menu_aliases = ([ ]);
  set_short("Pub");
  set_long(
    "You are in a pub.  You can buy drinks here.\n"
    "There is a menu here that you can read.\n");
  set_light(60);
  menu_header = "The menu reads:";
  display_headings = 1;
  ::create();
  menu_object = clone_object("/obj/misc/menu");
  menu_object->set_pub(this_object());
  menu_object->move(this_object());
  menu_object->reset_get();
// Taniwha 1996 LEAVE it out of hidden as hidden is screwed
  //hidden_objects += ({ menu_object });
  this_object()->add_property("no_undead",1);
// Cailet 1997 tracking bars for the songster quest.
  BAR_TRACKER->add_bar(file_name(this_object()));
}
 
void init() {
  ::init();
  add_action("buy", "buy");
  add_action("do_read","read");
  add_action("buy", "order");
}
 
string get_domain() {
  string fname = file_name(this_object());
  string *dom = explode(fname,"/");
  return dom[1];
}

int get_min_per_heal(string type, int volume) {
  int min_per_heal;

  if(get_domain() == "newbie") 
    min_per_heal = NEWBIE_WCOST;
  else
    min_per_heal = NORMAL_WCOST;
  
  if(type == ALCOHOL)
    min_per_heal = (1000-volume)*min_per_heal/1000;
  else if(type == SOFTDRINK) 
    min_per_heal = (1000+volume)*min_per_heal/1000;
  if(min_per_heal < 1) min_per_heal = 1;
  return min_per_heal;
}

void add_menu_item(string name, string type, int basecost, int heal, int volume,
                   int intox, string drmess, string othmess) {
  int num_type, cost, min_per_heal;

  if (!sizeof(prices_used))
    restore_object(file_name(this_object()),1);
  if (!prices_used[name]) prices_used[name] = 1000;
  cost = basecost*prices_used[name]/1000;

  min_per_heal = get_min_per_heal(type,volume);
  if(cost < heal*min_per_heal+1) {
    cost = heal*min_per_heal+1;
    prices_used[name] = 1000*cost/basecost+1;
  }

  menu_items[name] = ({ type, cost, heal, volume, intox,
                              drmess, othmess, basecost });
}
 
void add_menu_items(mixed *drinks) {
  int loop;

  for(loop=0; loop<sizeof(drinks); loop++) {
    if(sizeof(drinks[loop]) == 5) {
      mixed *dr;
 
      dr = drinks[loop];
      add_menu_item(dr[0], dr[1], dr[2], dr[3], dr[4], dr[5], dr[6], dr[7]);
    }
  }
}
 
mapping query_menu_items() {
  return menu_items;
}
 
int remove_menu_item(string name) {
  int temp;

  if (!menu_items[name])
    return 0;
  menu_items = m_delete(menu_items, name); 
  return 1;
}

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
 
string string_menu(string *items) {
  int loop,temp;
  string str;
  str = ""; 
  for(loop = 0; loop < sizeof(items); loop++)
  {
  temp = menu_items[items[loop]][DR_COST]*MONEY_TRACKER->
       query_adj_fact(TAVFLAG)/1000;
           temp =do_cha_adjust(temp,this_player()->query_cha());
  temp  = do_race_adjust(temp,this_player()->query_race());
 
    str += sprintf("    %-20s %s\n", items[loop],
             MONEY_HAND->money_value_string(temp));
  }
  return str;
}
 
string read() {
  int loop, temp;
  string *fpos;
  string str, ret, *stuff;
 
  fpos = ({ });
  ret = "\n" + menu_header + "\n";
  stuff = m_indices(menu_items);
  for(loop=0;loop<sizeof(stuff);loop++) {
    if(menu_items[stuff[loop]][DR_TYPE] == FOOD) {
      fpos += ({ stuff[loop] });
    }
  }
  if(sizeof(fpos) > 0) {
    if(display_headings) {
      str = "Meals\n";
    }
    fpos = sort_array(fpos,"compare");
    str += string_menu(fpos);
    ret += sprintf("%-=*s\n", (int)this_player()->query_cols(), str);
  }
  fpos = ({ });
  for(loop=0;loop<sizeof(stuff);loop++) {
    if(menu_items[stuff[loop]][DR_TYPE] == SOFTDRINK) {
      fpos += ({stuff[loop]});
    }
  }
  if(sizeof(fpos) > 0) {
    if(display_headings) {
      str = "Drinks\n";
    }
    fpos = sort_array(fpos,"compare");
    str += string_menu(fpos);
    ret += sprintf("%-=*s\n", (int)this_player()->query_cols(), str);
  }
  fpos = ({ });
  for(loop=0;loop<sizeof(stuff);loop++) {
    if(menu_items[stuff[loop]][DR_TYPE] == ALCOHOL) {
      fpos += ({stuff[loop]});
    }
  }
  if(sizeof(fpos) > 0) {
    if(display_headings) {
      str = "Alcoholic Beverages\n";
    }
    fpos = sort_array(fpos,"compare");
    str += string_menu(fpos);
    ret += sprintf("%-=*s\n", (int)this_player()->query_cols(), str);
  }
  return ret;
}
int do_read(string str)
{
  int temp;
   if(str && lower_case(str) == "menu")
   {
  if((temp = do_race_adjust(temp,this_player()->query_race()))==
         -101) {
                write("This establishment refuses to deal "
                      "with your race.\n");
                return 1;
  }
      write(read());
      return(1);
   }
   notify_fail("Read what?\n");
   return(0);
}

// Fix by !Aragorn
int compare(string a, string b) {
   return menu_items[a][DR_COST]-menu_items[b][DR_COST];
}
 
void set_menu_header(string header) {
  menu_header = header;
}
 
string query_menu_header() {
  return menu_header;
}
 
void set_display_headings(int value) {
  display_headings = value;
}
 
int query_display_headings() {
  return display_headings;
}
 
void add_menu_alias(string alias, string actual) {
  menu_aliases[alias] = actual;
}
 
mapping query_menu_aliases() {
  return menu_aliases;
}
 
int remove_menu_alias(string alias) {
  menu_aliases = m_delete(menu_aliases, alias);
}
 
int buy(string str) {
  int temp, volume, intox, heal, error, type,forplay;
   int i;
  //mixed *cost;
  int cost;
// I hope cost didn't need to be mixed :)   Anirudh
  string *list;
  string drmess, othmes;
  object food,forwho;

  list = explode(str," ");
  if(!sizeof(list))
  {
     notify_fail("Buy item [for player]");
     return 0;
  }
  forplay = member_array("for",list);
  if(forplay > 0)
  {
      if(sizeof(list) == forplay)
      {
        notify_fail("Buy what for whom ?.\n");
        return 0;
      }
      notify_fail("The person doesn't seem to be here.\n");
   forwho = present(list[forplay+1]);
      if(!forwho)
      {
         return 0;
      }
      if(!present(forwho))
      {
         return 0;
      }
      if(!forwho->query_consent("drinks"))
      {
        write((string)forwho->query_cap_name()+" refuses your offer.\n");
        tell_object(forwho,this_player()->query_cap_name()+" tries to buy you something, but you refuse it.\n");
        say((string)this_player()->query_cap_name()+" offers to buy "+forwho->query_cap_name()+" something.\n",({ this_player(),forwho}) );
      return 1;
      }
      str = "";
      for(i = 0;i < forplay;i++)
      {
         str += list[i];
         if(i != (forplay-1)) str += " ";
      }
  }
  else forwho = this_player();

  if (menu_aliases[str])
    str = menu_aliases[str];
  if(!menu_items[str]) 
   {
    notify_fail("Sorry, "+str+" is not on the menu.\n");
    return 0;
  }
  heal = menu_items[str][DR_HEAL];
  cost = menu_items[str][DR_COST];
  switch (menu_items[str][DR_TYPE]) {
    case FOOD : type = D_FOOD;
                break;
    case ALCOHOL : type =D_ALCOHOL;
                break;
    case SOFTDRINK : type = D_ALCOHOL;
                break;
  }
  volume = menu_items[str][DR_VOLUME];
  if(menu_items[str][DR_TYPE]==SOFTDRINK){volume=-volume;}
  intox = menu_items[str][DR_INTOX];
  drmess = menu_items[str][DR_DRMESS];
  othmes = menu_items[str][DR_OTHMES];
   cost=cost*MONEY_TRACKER->query_adj_fact(TAVFLAG)/1000;
  cost=do_cha_adjust(cost,this_player()->query_cha());
  if((cost = do_race_adjust(cost,this_player()->query_race()))==
          -101) { notify_fail("This establishment refuses to deal "
                     "with your race.\n");
                  return 0;
  }
  if(this_player()->query_value() < cost) {
    notify_fail("You are too poor to afford that.\n");
    return 0;
  }

// Cailet 1997 for songster quest
  if (forwho == this_player() && intox && forwho->query_guild_name() == "bard")
    call_out("songster_quest",1,forwho);

#ifdef AUTOMATIC
  this_player()->pay_money( ({ "copper", cost }) );
  forwho->adjust_volume(type, volume);
  forwho->adjust_hp(heal,this_player());
  forwho->adjust_intox(intox);
   if(forwho != this_player())
   {
      tell_room(this_object(),(string)this_player()->query_cap_name()+" buys "+
      (string)forwho->query_cap_name()+" "+str+".\n",({ }));
   }
  tell_object(forwho,"You "+drmess+".\n");
  tell_room(this_object(),(string)forwho->query_cap_name()+
    " "+othmes+".\n",({ forwho }));
#else
  food = clone_object("obj/food");
  food->set_type(type);
  food->set_name(str);
  food->set_short(str);
  food->set_heal(heal);
  food->set_intox(intox);
  food->set_volume(volume);
  food->set_weight(5);
  food->set_consume_write(drmess);
  food->set_consume_say(othmes);
  error = (int)food->move(forwho);
  if(error) {
    write("You cannot carry that much.\n");
    food->dest_me();
    return 1;
  }
  this_player()->pay_money( ({"copper",cost }) );
#endif
  if(!(this_player()->query_creator()) &&
    strsrch(this_player()->query_name(),"test") == -1) {
  if (!m_sizeof(prices_used))
    restore_object(file_name(this_object()),1);
  
  cost -= heal*get_min_per_heal(menu_items[str][DR_TYPE],
                     sqrt(volume*volume+0.0));
  pts_healed+=heal;
  gross_inc+=cost;
  check_adjust_prices();
  if(m_sizeof(prices_used)) 
    save_object(file_name(this_object()));
  }
  return 1;
}

int do_race_adjust(int amt, string race) {
  int temp;
  if(!m_sizeof(race_prefs)) race_prefs = ([ ]);
  if(!race_prefs[race]) return amt;
  if(race_prefs[race] == -1) return -101;
  temp = amt*race_prefs[race]/100-1;
  if(temp < amt) return amt;
  return temp;
}

int do_cha_adjust(int amt, int cha) {
  int temp;
  if(!cha) return amt;
  if(cha > 19) cha = 19;
  if(cha > AVG_CHA) {
    temp = 10*(cha - AVG_CHA)*CHA_AD/(18-AVG_CHA);
    temp = amt*1000/(1000+temp)+1;
    if(temp > amt) return amt;
    return temp;
  }
  if(cha < AVG_CHA) {
    temp = 10*(AVG_CHA-cha)*CHA_AD/(AVG_CHA-3);
    temp = amt*(1000+temp)/1000-1;
    if(temp < amt) return amt;
    return temp;
  }
  return amt;
}

void check_adjust_prices() {
  int elapsed_time = TIMEKEEPER->query_running_time()-
        last_adjust;
  if (elapsed_time < 0 || last_adjust == 0) {
    gross_inc = 0;
    pts_healed = 0;
    last_adjust = TIMEKEEPER->query_running_time();
  }
  else if ((elapsed_time > 2*BASE_DAY && pts_healed > 1000) || 
             (elapsed_time > 5*BASE_DAY && pts_healed > 200))
    adjust_prices();
}

void adjust_prices() {
  int time_now, time_elapsed, rate_now, i, j, use_flag, best_num,
    best_rate, sign, temp_rate;
  int perc;
  mapping temp_prices;
  string *item_ind;
  if (!m_sizeof(prices_used))
    restore_object(file_name(this_object()),1);
  time_now = TIMEKEEPER->query_running_time();
  time_elapsed = time_now-last_adjust;
  if (time_elapsed < 3600) time_elapsed = 3600;
  rate_now = 168*gross_inc/(time_elapsed/3600);
  if(rate_now > prices_used["rate"]) { sign = last_sign; }
  else { 
    if(last_sign == 1) sign = 0;
    else sign = 1;
  }
  last_sign = sign;
  for (i = sizeof(best_prices); i < 6; i++)
    best_prices+= ({ ([ ]) });
  for (i=0; i<=5; i++) {
    if (!use_flag) {
      if (!m_sizeof(best_prices[i])) {
        item_ind = m_indices(prices_used);
        best_prices[i] = m_delete(prices_used,"dummy");
        if(!best_prices[i]["used"])
          best_prices[i]["used"] = 0;
        best_prices[i]["rate"] = rate_now;
        use_flag = 1;
      }
    }
    if (!use_flag) {
      if (best_prices[i]["rate"] < rate_now) {
        temp_prices = m_delete(best_prices[i],"dummy");
        best_prices[i] = m_delete(prices_used,"dummy");
        if (!best_prices[i]["used"]) best_prices[i]["used"] = 0;
        best_prices[i]["rate"] = rate_now;
        prices_used = m_delete(temp_prices,"dummy");
        rate_now = prices_used["rate"];
      }
    }
    if (m_sizeof(best_prices[i]) && best_prices[i]["rate"] > best_rate) {
      best_num = i;
      best_rate = best_prices[i]["rate"];
    }
  }
  item_ind = m_indices(best_prices[best_num]);
  prices_used = m_delete(best_prices[best_num],"dummy");
  if (++best_prices[best_num]["used"] > 2) best_prices[best_num] = ([ ]);
  for (i=0; i<sizeof(item_ind); i++) {
    if (item_ind[i] != "used" && item_ind[i] != "rate") {
      if (!item_ind[i]) prices_used = m_delete(prices_used,item_ind[i]);
      else {
        if((perc = 2000/menu_items[item_ind[i]][1]) < 300) perc = 300;
        if (sign) prices_used[item_ind[i]]=prices_used[item_ind[i]]*
          (1000+random(perc))/1000;
        else prices_used[item_ind[i]]=prices_used[item_ind[i]]*
          1000/(1000+random(perc));
      if ( prices_used[item_ind[i]] < 10) prices_used[item_ind[i]] = 10;
      menu_items[item_ind[i]][1] = menu_items[item_ind[i]][7]*
               prices_used[item_ind[i]]/1000;
      if(menu_items[item_ind[i]][1] < 1) menu_items[item_ind[i]][1] = 1;
      }
    }
  }
  last_adjust = time_now;
  pts_healed = 0;
  gross_inc = 0;
  prices_used["used"] = 0;
  if(m_sizeof(prices_used)) 
    save_object(file_name(this_object()));

}
void dest_me() {
  if (menu_object)
    menu_object->dest_me();
  ::dest_me();
}

void event_fight_in_progress() {
  mixed *dest;
object ob;
  int i;

  dest = query_dest_dir();
  for (i=1;i<sizeof(dest);i+=2)
    if (objectp(dest[i]))
      event(dest[i], "pub_brawl", this_object());
    else
      if(ob=find_object(dest[i]))
        event(ob,"pub_brawl", this_object());
}

// Cailet 1997 for songster quest

void songster_quest(object bard) {
   int *bars_visited, bar_num;

   if(bard->query_property("SONGSTER_DONE")) return;
   bars_visited = bard->query_property("bars_visited");
   bar_num = BAR_TRACKER->query_bar_number(file_name(this_object()));
   if (member_array(bar_num, bars_visited) == -1) {
      if (!bars_visited) bars_visited = ({ bar_num });
      else bars_visited += ({ bar_num });
      bard->add_property("bars_visited",bars_visited);
      write("You sip your drink and feel a little more knowledgable about "
            "the world.\n");
   }
   return;
} /* songster_quest() */

