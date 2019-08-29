#include "corpse.h"
inherit "/std/container";
inherit "std/living/carrying";

#include <bit.h>

#define DECAY_TIME      60
#define RAISE_CHANCE  25
#define PC_RAISE_CHANCE 50
#define PATH "/obj/"

int wasplayer = 0;
string owner, race_ob, race_name;
string *bits_gone;
int decay;
/* for nicer formatting of exa corpse */
object weapon, *armours;

int query_auto_load() { return 1; }

void set_race_ob(string race_ob);

int query_corpse() { return 1; }
string query_owner() { return owner; }

int prevent_insert() {
    write("The corpse is too big.\n");
    return 1;
}

/* Next function is Hamlet's.  Decides whether undead are allowed
   in the room
*/
int undead_okay(object room) {
    int i,maxi;
    int CORPSEFINE = 1;

    /* Next section excellent but considered unnecessary, Taniwha 1995 */
    /*
      string roomfile = virtual_file_name(room);
      maxi = sizeof(no_undead_dir);

      for(i=0;i<maxi;i++)
	if( no_undead_dir[i] == roomfile[0..(strlen(no_undead_dir[i]))] ) {
	  CORPSEFINE = 0;
	  break;
	}
    */

   if("/global/omiq.c"->flag_in_progress())
      CORPSEFINE = 0;
    if( room->query_property("no_undead") )
	CORPSEFINE = 0;

    return CORPSEFINE;
}

void raise_me(object ob)
{
    object *stuff, cow;
    int i;

    i = random(100);
    if(i<=50)
	cow=clone_object(PATH+"chars/skeleton.c");
    else
    if(i<=80)
	cow=clone_object(PATH+"chars/zombie.c");
    else
    if(i<=90)
	cow=clone_object(PATH+"chars/wraith.c");
    else
    if(i<=98)
	cow=clone_object(PATH+"chars/specter.c");
    else
	cow=clone_object(PATH+"chars/lich.c");

    if(owner)
	cow->set_short(cow->query_short()+" of "+owner);
    stuff = all_inventory(ob);
    for(i=0;i<sizeof(stuff);i++)
	if(stuff[i])
	    stuff[i]->move(cow);
    cow->move(environment(ob));
    tell_room(environment(ob),"You hear the howl of a tortured spirit.\n"+
      "Suddenly, a "+
      cow->query_name()+" stands where the corpse was.\n");
    cow->init_equip();
    ob->dest_me();
    return;
}

string query_name() {
    if (!::query_name())
	return "someone";
    return ::query_name();
}

void setup() {
    bits_gone = ({ });
    owner = "noone";
    race_name = "womble";
    decay = 10;
    add_plural("corpses");
    add_alias("corpse");
    set_short("corpse");
    set_long("A corpse, it looks dead.\n");
    set_weight(1300);
    set_race_ob("/std/races/unknown");
    set_main_plural("corpses");
}

void set_owner(string n, object ob) {
    owner = n;
    set_name("corpse");
    add_alias("corpse of " + n);
    set_short("corpse of " + capitalize(n));
    if ( ob && ob->query_main_plural() )
	set_main_plural("corpses of "+ob->query_main_plural());
    else
	set_main_plural("corpses of "+pluralize(n));
    add_plural("corpses");
    set_long("This is the dead body of "+capitalize(n)+".\n");
    if (ob && ob->query_weight()) set_weight(ob->query_weight());
    else set_weight(STD_CORPSE_WEIGHT);
    set_heart_beat(DECAY_TIME);
    // Taniwha 1996, supress clean up if a player pegs out in a room
    if(ob)
    {
	if(interactive(ob))
	{
	    wasplayer = 1;
	    environment(ob)->add_timed_property("no_clean_up",1,30000);
	}
    }

}

void set_race_name(string str) { race_name = str; }
string query_race_name() { return race_name; }
string query_race() { return race_name; }

void decay() {
    object ob,ob2;
    object *obs;
    int i;
    decay -= 1;
    if(!race_name)
    {
	if(race_ob)
	    race_name = (string)race_ob->query_name();
	else race_name = "unknown";
    }
    if (decay == 7) {
	set_short("somewhat decayed remains of "+query_name());
	set_main_plural("somewhat decayed remains of "+query_name());
    }
    if (decay == 5) {
	set_short("decayed remains of "+race_name);
	set_main_plural("decayed remains of "+race_name);
	set_long("This is the dead body of "+add_a(race_name)+".\n");
    }
    if (decay > 0)
	return ;
    /* Hamlet visited the next line */
    if( ((!wasplayer && (random(100)<=RAISE_CHANCE)) ||
	(wasplayer && (random(100)<=PC_RAISE_CHANCE)))
      && undead_okay(environment(this_object())) )
    {
	raise_me(this_object());
	return;
    }
    /* dump the equip */
    if(wasplayer) {
	obs = all_inventory(this_object());
	for(i = 0; i < sizeof(obs); i++)
	{
	    if(obs[i]) obs[i]->move(environment(this_object()));
	}
    }
    //destruct(this_object());
    this_object()->dest_me();
}

set_race_ob(string s)
{
    race_ob = s;
}

query_race_ob()
{
    return race_ob;
}

find_inv_match(s)
{
    string bit;
    object bitobj, weap;
    int i,j;

    bit = race_ob->query_possible_bits(s);
    if (!bit || !sizeof(bit)) return all_inventory();

    bit -= bits_gone;    /* take out of all possible bits the bits_gone */
    if (!sizeof(bit)) return bit;

    weap = (object) this_player()->query_weapon();
    if(!weap) {
	write("You can't cut bits from a corpse with your bare hands.\n");
	return ({ });
    } else if(!weap->id("dagger") && !weap->id("knife")) {
	write("You can only cut things from a corpse with a knife or dagger.\n");
	return ({ });
    }
    bit = race_ob->query_bit(bit[0]);
    bitobj = clone_object("/std/bit");
    bitobj->set_race_ob(race_ob);
    if (race_name) bitobj->set_race_name(race_name);
    else bitobj->set_race_name(race_ob->query_name());
    bitobj->set_corpse_weight(query_weight());
    bitobj->set_bit(bit[0], decay*10);
    bitobj->set_decay_bit(bit[0]);
    for (i = 0; i < sizeof(bits_gone); i++) {
	j = member_array(bits_gone[i], bit[BIT_EXTRA]);
	if (j >= 0)
	    bitobj->remove_bit(bits_gone[i]);
    }
    bits_gone += ({ bit[BIT_NAME] }) + bit[BIT_EXTRA][3..50];
    if (s == "head") {
	set_long(query_long() + "It is decapitated.\n");
	set_short("decapitated corpse of " + capitalize(owner));
    }
    if (environment())
	bitobj->move(environment());
    return ({ bitobj });
}

query_bits_gone() { return bits_gone; }

/* this for formatting of objects sake */
object *query_armours() { return armours + ({ }); }
void set_armours(object *arm) { armours = arm; }
void remove_armour(object arm) { armours -= ({ arm }); }

object query_weapon() { return weapon; }
void set_weapon(object wpn) { weapon = wpn; }
void unwield_weapon(object wpn) { if(weapon == wpn) weapon = 0; }


string query_possessive() { return "its"; }

/* Converted from call_outs to heartbeats by Baldrick. after a look at Aragorns
   code on RD sept '93 */

void heart_beat()
{
    decay();
} /* void heartbeat */
