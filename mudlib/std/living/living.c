#include "living.h"
inherit "/std/living/alignment";
inherit "/std/living/curses";
inherit "/std/living/death"; /* no pun intended.. :=) */
inherit "/std/living/force";
inherit "/std/living/skills";
inherit "/std/living/money";
inherit "/std/living/spells";
inherit "/std/living/equip";
inherit "/std/living/gender";
inherit "/std/living/stats";
inherit "/std/living/carrying";
inherit "/std/living/health";
inherit "/std/container";

string msgout,
msgin,
mmsgout,
mmsgin;
int verbose, level;
status dead;
static mixed *it_them;
static object *followers;
static mixed remember_follow;
mixed attack_data,
attack_name;

// Protoypes.. 
int query_total_ac();

void create() 
{
    equip::create();
    curses::create();
    spells::create();
    skills::create();
    health::create();
    enable_commands();
    attack_name = ({ });
    attack_data = ({ });
    followers = ({ });
    max_hp = 1;
    max_gp = 1;
    container::create();
    it_them = ({ this_object() });
    dead = 0;
} /* create() */

void living_commands() 
{
    add_action("do_equip", "equip");
    add_action("do_hold", "wi*eld");
    add_action("do_unhold", "unwi*eld");
    add_action("do_wear", "wea*r");
    add_action("do_unwear", "unwea*r");
    add_action("do_unhold", "unho*ld");
    add_action("do_hold", "ho*ld");
    add_action("do_equip", "eq*uip");
    add_action("remove", "remove");
    add_action("follow", "fo*llow");
    add_action("lose", "lo*se");
    add_action("unfollow", "unf*ollow");
    add_action("follow_dummy", "FOLLOW_DUMMY");
    combat_commands();
    //skill_commands();
} /* living_commands() */

/* Basic stuff, does this thing live or not?
 * Timion added something like this some time ago and I thought it wasn't 
 * nessesary, but it may be?
 */
/* Maybe this should be in health.c or stats.c?
 * Baldrick, aug '95 
 */

void set_dead(status bing)
{
    dead = bing;
    return; 
}

int query_dead()
{
    return dead;
}

/* For compatibility: */

int query_alive()
{
    return !dead;
}

/* move stuff
 */
int test_add(object ob, int flag) { return !flag; }
int test_remove(object ob, int flag) { return !flag; }

static int in_move;

int query_in_move() { return in_move; }

/* thats it... 
 * no need for stupid checking to see if we are attacking something in
 * here stuff.
 */
varargs mixed move_player(string dir, mixed dest, mixed message,
  object followee, mixed enter) {
    int i, ret, no_see;
    string arr, leave, ppl, my_short;
    object last, *ok_follow, new_env;

    if (!msgout) {
	msgout = "@$N leaves $T.";
	msgin = "@$N arrives from $F.";
    }
    if (!mmsgout) {
	mmsgout = "@$N disappears in a puff of smoke.";
	mmsgin = "@$N appears out of the ground.";
    }
    last = environment();
    if(!this_object()->query_invis()) {
	my_short = (string)this_object()->short();
	if(my_short) my_short = capitalize(my_short);
    }

    if(!my_short || my_short == "" || (stringp(message) && message == "none")) {
	no_see = 1;
    } else if(!dir || dir == "X") { /* we are teleporting */
	leave = implode(explode(mmsgout, "$N"), my_short) + "\n";
	arr = implode(explode(mmsgin, "$N"), my_short) + "\n";
    } else if(!sizeof(followers) && !followee) {
	if (!enter || !pointerp(enter))
	    enter = ({ 0, "somewhere" });
	if (pointerp(message))
	    message = message[0];
	leave = implode(explode(implode(explode((message?message:msgout), "$N"), 
	      my_short), "$T"), dir)+"\n";
	switch (enter[0]) {
	case 0 :
	    arr = implode(explode(implode(explode(msgin, "$N"), my_short), "$F"),
	      enter[1])+"\n";
	    break;
	case 1 :
	    arr = implode(explode(enter[1], "$N"), my_short)+"\n";
	    break;
	}
    }
    if(arr) ret = move(dest, arr[1..1000], leave[1..1000]);
    else ret = move(dest);

    if(ret) return 0;

    new_env = environment();
    if (interactive(this_object()) && !query_property(UNKNOWN_MOVE_PROP)) {
	if (verbose) {
	    this_object()->ignore_from_history("look");
	    command("look");
	} else {
	    this_object()->ignore_from_history("glance");
	    command("glance");
	}
    }
    if(!dir || dir == "X" || (!sizeof(followers) && !followee)) return 1;
    else if(no_see) return ({});

    in_move = 1;
    ok_follow = ({ this_object() });
    for (i=0;i<sizeof(followers);i++) {
	object *tmp;
	if (followers[i]) {
	    if(environment(followers[i])==last && !followers[i]->query_in_move()) {
		tmp = (object *)followers[i]->do_follow_command(dir);
		followers[i]->reset_remember_follow();
		if(tmp && sizeof(tmp)) {
		    tell_object(followers[i], "You follow " + my_short + " "+dir+".\n");
		    ok_follow += tmp;
		} else {
		    tell_object(followers[i], "You fail to follow " +
		      my_short + " " +dir+ ".\n");
		}
	    }
	} else {
	    write("One of the people following you just quit or died a horrible "
	      "death.\n");
	    followers = delete(followers, i, 1);
	    i--;
	}
    }
    in_move = 0;
    if (followee)
	return ok_follow;
    /*
     * Yes we have to do some silly things for multiple exit and enter
     * messages lest they make no sense.
     */
    ppl = capitalize(query_multiple_short(ok_follow));
    if (pointerp(message))
	message = message[1];
    else
	message = "@$N leave $T.";
    leave = implode(explode(implode(explode(message, "$N"), 
	  ppl), "$T"), dir) + "\n";
    if (!enter || !pointerp(enter))
	enter = ({ 0, "somewhere" });
    switch (enter[0]) {
    case 0 :
	arr = "@" + ppl + " arrive from " + enter[1] + ".\n";
	break;
    case 1 :
	arr = implode(explode(enter[2], "$N"), ppl);
	break;
    }
    event(last, "exit", extract(leave, 1), new_env, ok_follow);
    event(new_env, "enter", extract(arr, 1), last, ok_follow);
    if(sizeof(ok_follow) > 1)
	tell_object(this_object(), capitalize(query_multiple_short(ok_follow-
	      ({ this_object() })))+" follow" + /* add 's' if only one follower */
	  (sizeof(ok_follow) == 2?"s":"") + " you.\n");
    return ok_follow;
} /* move_player() */

object *do_follow_command(string dir)
{
    remember_follow = ({ previous_object(), dir });
    this_object()->ignore_from_history("FOLLOW_DUMMY");
    command("FOLLOW_DUMMY");
    return remember_follow;
}

void reset_remember_follow()
{
    remember_follow = 0;
}

int follow_dummy()
{
  // Wonderflug, passed out stops following
  if ( this_object()->query_property("passed out") )
  {
    tell_object(this_object(), "You're in no condition to follow anyone.\n");
    return 0;
  }
    // Taniwha, stop it barfing
    if((sizeof(remember_follow) > 1) && remember_follow[0] && remember_follow[1])
	remember_follow = (object *)environment()->do_exit_command(0,
	  remember_follow[1], this_object(), remember_follow[0]);
    if(remember_follow && sizeof(remember_follow)) return 1;
    else return 0;
}

int cannot_get_stuff() { return 1; }

mixed *stats() {
    return container::stats() + ({
    ({ "max_hp", max_hp }),
    ({ "hp",  hp }),
    ({ "max_gp", max_gp }),
    ({ "gp", gp }),
    ({ "Body AC (dex bonus) mod.", query_body_ac() }),
    ({ "Equipment AC mod.", query_equip_ac() }),
    ({ "Total AC", query_total_ac() }),
    ({ "Damage bonus", query_damage_bonus() }),
    ({ "Tohit bonus", query_tohit_bonus() }),
    ({ "Str", query_str() }),
    ({ "Int", query_int() }),
    ({ "Dex", query_dex() }),
    ({ "Con", query_con() }),
    ({ "Wis", query_wis() }),
    ({ "Cha", query_cha() }),
    ({ "tmp Str", query_tmp_str() }),
    ({ "tmp dex", query_tmp_dex() }),
    ({ "tmp Con", query_tmp_con() }),
    ({ "tmp Int", query_tmp_int() }),
    ({ "tmp Wis", query_tmp_wis() }),
    ({ "tmp Cha", query_tmp_cha() }),
    ({ "bonus Str", query_bonus_str() }),
    ({ "bonus Int", query_bonus_int() }),
    ({ "bonus Dex", query_bonus_dex() }),
    ({ "bonus Con", query_bonus_con() }),
    ({ "bonus Wis", query_bonus_wis() }),
    ({ "bonus Cha", query_bonus_cha() }),
    ({ "Gender", query_gender_string() }),
    ({ "total money", query_value() }),
    ({ "Exp", query_xp() }),
    ({ "Total xp", query_total_xp() }),
    ({ "GameAlignment", query_align_name() }),
    ({ "Playerset Alignment", query_playerset_alname() }),
  }) ; /* change to + equip::stats(); */
}

void dest_me() {
    object *ob;
    int i;

    ob = deep_inventory(this_object());
    for (i=0;i<sizeof(ob);i++)
	if(ob[i])
	    ob[i]->dest_me();
    container::dest_me();
}


// REALLY bogus .. used for "look it" and remembering what "it"
// is (the last thing you've looked at.  Needed environment()
// checks, so Radix was here, Jan 7, 1996
// This is deeply rooted in /secure/simul_efun/find_match.c as well
mixed *query_it_them()
{
   int i;
   if(!this_object()) return it_them;
   for(i=0; i<sizeof(it_them); i++)
      if(environment(this_object()) != environment(it_them[i]))
         it_them = delete(it_them,i,1);
   return it_them;
}
mixed *set_it_them(mixed *i) { return (it_them = i); }

int add_follower(object ob) {
    if (ob == this_object())
	return 0;
    if (member_array(ob, attacker_list) != -1)
	return 0;
    if (member_array(ob, followers) == -1)
	followers += ({ ob });
    return 1;
}

int remove_follower(object ob) {
    int i;

    if ((i=member_array(ob, followers)) != -1) {
	followers = delete(followers, i, 1);
	return 1;
    }
    return 0;
}

int follow(string str) {
    mixed obs;
    object ob;

    if (!str) {
	notify_fail("Syntax: follow <person>\n");
	return 0;
    }
    if ( this_object()->query_property("just followed and failed") )
    {
	notify_fail("You're too tired of trying to keep up to people to try "
	  "and follow someone again.\n");
	return 0;
    }
    obs = find_match(str, environment(),1);
    if (!sizeof(obs)) {
	notify_fail("Could not find "+str+".\n");
	return 0;
    }
    // Fixing up by Wonderflug, nov '95
    ob = obs[0];
    if ( !ob->query_consent("follow") &&
      random((int)ob->query_dex()) < random((int)this_object()->query_dex()) )
    {
	tell_object(ob, this_object()->query_cap_name()+" tries to follow you, "
	  "but you manage evade "+this_object()->query_objective()+".\n");
	this_object()->add_timed_property("just followed and failed", 1, 10);
	notify_fail("You try to follow "+ob->query_cap_name()+", but "
	  "you can't keep up to "+ob->query_pronoun()+".\n");
	return 0;
    }

    if ( !ob->add_follower(this_object()) )
    {
	notify_fail("You can only follow living things.\n");
	return 1;
    }
    write("You follow "+ob->query_cap_name()+".\n");
    tell_room(environment(this_object()), this_object()->query_cap_name()+
      " follows "+ob->query_cap_name()+".\n", ({ ob, this_object() }) );
    tell_object(ob, this_object()->query_cap_name()+" follows you.\n");
    return 1;
}

int unfollow(string str) {
    int i;
    object *ok, *obs;
    string s;

    if (!str) {
	notify_fail("Syntax: unfollow <person>\n");
	return 0;
    }
    obs = find_match(str, environment(),1);
    if (!sizeof(obs)) {
	notify_fail("I cannot find "+str+" to unfollow.\n");
	return 0;
    }
    ok = ({ });
    for (i=0;i<sizeof(obs);i++)
	if (obs[i]->remove_follower(this_object()))
	    ok += obs[i..i];
    if (!sizeof(ok)) {
	notify_fail("You are not following "+query_multiple_short(obs)+".\n");
	return 0;
    }
    write("You stop following "+(s=query_multiple_short(ok))+".\n");
    say(this_object()->query_cap_name()+" stops following "+s+".\n", ok);
    ok += ({ "you" });
    for (i=0;i<sizeof(ok)-1;i++)
	tell_object(ok[i], this_object()->query_cap_name()+
	  " stops following "+query_multiple_short(ok - ({ ok[i] }))+".\n");
    return 1;
}

int lose(string str) {
    int i;
    object *ok, *obs;
    string s;

    if (!str) {
	notify_fail("Syntax: lose <person|everyone>\n");
	return 0;
    }
    if (str == "everyone")
	obs = followers;
    else
	obs = find_match(str, environment());
    if (!sizeof(obs)) {
	notify_fail("I cannot find "+str+" to lose.\n");
	return 0;
    }
    ok = ({ });
    for (i=0;i<sizeof(obs);i++)
	if (remove_follower(obs[i]))
	    ok += obs[i..i];
    if (!sizeof(ok)) {
	notify_fail("You are not being followed by "+
	  query_multiple_short(obs)+".\n");
	return 0;
    }
    write("You lose "+(s=query_multiple_short(ok))+".\n");
    say(this_object()->query_cap_name()+" loses "+s+".\n", ok);
    ok += ({ "you" });
    for (i=0;i<sizeof(ok)-1;i++)
	tell_object(ok[i], this_object()->query_cap_name()+
	  " loses "+query_multiple_short(ok - ({ ok[i] }))+".\n");
    return 1;
}

object query_current_room() { return environment(); }

mixed *query_followers() { return followers; }

varargs int adjust_money(mixed amt, string type) {
   int ret = money::adjust_money(amt, type);
   catch(MONEY_HANDLER->update_money(amt, type, this_object()));
   return ret;
}

mixed *query_money_array() { 
    return money::query_money_array();
} /* query_money_array() */

int query_money(string type) { 
    return money::query_money(type);
} /* query_money() */

int query_value() { return money::query_value(); }
query_teleport() {
    if (!msgin) {
	return 0;
    }
    if (!mmsgin) {
	return 1;
    }
}                     
/* AC 100 is the base, all AC is subtracted from this to get the AD&D AC */

// Without this_object()-> /obj/monster.c is ignored - fixed by Radix
int query_total_ac()
{
   int eac = this_object()->query_equip_ac();
   int bac = this_object()->query_body_ac();
// return 100 - ( eac + bac);
   int totac = 100 - ( eac + bac );
   if(totac < -100) return -100;
   return totac;
}


int do_hold(string woo)
  {
  object *boo;
  int i;

  if (!woo)
    return notify_fail("Hold / Wield what ?.\n");

  // AAArrrggghhhh find_match() doesn't work... -Aragorn
  // boo = find_match(woo, this_object());
  boo = all_inventory(this_object());
  for(i=0;i<sizeof(boo);i++)
    if (!boo[i]->id(woo)) boo[i] = 0;
  boo -= ({ 0 });

  if (!sizeof(boo))
    return notify_fail("You aren't carrying that.\n");

  // Somewhat nasty but does the trick... -Aragorn
  boo -= (mixed *)this_object()->query_held_ob();

  /* Somehow, this is not working.. */
  if (!sizeof(boo))
    return notify_fail("You are already holding that!\n");

  if (!boo[0]->query_holdable())
    return notify_fail("You can't " + query_verb() + " this.\n");
  
  if (boo[0]->query_in_use())
    return notify_fail("You are already using it.\n");

  // At the moment you can only hold one thing at the time. -Aragorn
  // if (!hold_ob(boo)) return 0;
  return hold_ob(boo[0]);
}

int do_unhold(string woo)
  {
  object *boo;
  int i;

  if (!woo)
    return notify_fail("Unhold / unwield what ?\n");

  // AAArrrggghhhh find_match() doesn't work... -Aragorn
  // boo = find_match(woo, this_object());
  boo = all_inventory(this_object());
  for(i=0;i<sizeof(boo);i++)
    if (!boo[i]->id(woo)) boo[i] = 0;
  boo -= ({ 0 });


  // As nasty as it gets but I'm just trying to get it to work 
  // right now. Speedups later.
  // -Aragorn
  boo -= (all_inventory(this_object())-(mixed*)this_object()->query_held_ob());

  if (!sizeof(boo))
    {
    notify_fail("Why unhold something you don't have ?\n"); 
    return 0;
    }
  // At the moment you can only unhold one thing at the time. -Aragorn
  // unhold_ob (boo);
  return unhold_ob(boo[0]);
}

int do_wear(string woo)
  {
  object *boo;
  int i;
  int size;
  
  if (!woo)
    return notify_fail("Wear what ?\n");

  // AAArrrggghhhh find_match() doesn't work... -Aragorn
  // boo = find_match(woo, this_object());
  boo = all_inventory(this_object());
  for(i=0;i<sizeof(boo);i++)
    if (!boo[i]->id(woo)) boo[i] = 0;
  boo -= ({ 0 });

  if (!sizeof(boo))
    return notify_fail("You aren't carrying that.\n");

  // Somewhat nasty but does the trick... -Aragorn
  /* what does this do ? Baldy.. 
   * It gives me an error message here, but not in hold.c */
  boo -= (mixed *)this_object()->query_worn_ob();

  if (sizeof(boo))
    {
    if (!boo[0]->query_wearable())
      return notify_fail("This item can't be worn!\n");

    if (boo[0]->query_in_use())
      return notify_fail("It's already worn.\n");
  
    if (size = boo[0]->query_size() == 0)
      return notify_fail("It has no size set, complain to someone");

    size = size / 2;
    if (size < 1)
      size = 1;

    wear_ob(boo[0]);
    }
  return 1;
}

int do_unwear(string woo)
  {
  object *boo;
  int i;

  if (!woo)
    return notify_fail("Unwear what ?\n");

  // AAArrrggghhhh find_match() doesn't work... -Aragorn
  // boo = find_match(woo, this_object());
  boo = all_inventory(this_object());
  for(i=0;i<sizeof(boo);i++)
    if (!boo[i]->id(woo)) boo[i] = 0;
  boo -= ({ 0 });


  // As nasty as it gets but I'm just trying to get it to work 
  // right now. Speedups later.
  // -Aragorn
  boo -= (all_inventory(this_object())-(mixed*)this_object()->query_worn_ob());

  if (!sizeof(boo))
    {
    notify_fail("Why unwear something you don't have ?\n"); 
    return 0;
    }

  // At the moment you can only unwear one thing at the time. -Aragorn
   unwear_ob(boo[0]);
   return 1;
}

