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
    write("El cuerpo es demasiado grande.\n");
    return 1;
}

/* Next function is Hamlet's.  Decides whether undead are allowed
   in the room
*/
int undead_okay(object room) {
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
	cow->set_short(cow->query_short()+" de "+owner);
    stuff = all_inventory(ob);
    for(i=0;i<sizeof(stuff);i++)
	if(stuff[i])
	    stuff[i]->move(cow);
    cow->move(environment(ob));
    tell_room(environment(ob),"Escuchas el aullido de un espiritu torturado.\n"+
      "De pronto, un "+
      cow->query_name()+" aparece de las entranyas del cadaver, tragandoselo.\n");
    cow->init_equip();
    ob->dest_me();
	/* cuando mueres dejas las armas en el suelo... taria bien pillarlas y ekipar XD
	se pilla todas las weapons del suelo (incluso considerar cuales son mejores)
	y ale, a ekipar xD y a ver si cambiamos lo de ekipar, ke somos zombies pero no
	tontos, como cojones puede ponerse un cuero en lugar de una completa? xD */
    return;
}

string query_name() {
    if (!::query_name())
	return "alguien";
    return ::query_name();
}

void setup() {
    bits_gone = ({ });
    owner = "nadie";
    race_name = "womble";
    decay = 10;
	set_main_plural("cuerpos");
    add_plural("cuerpos");
    add_alias("cuerpo");
    set_short("cuerpo");
    set_long("Un cuerpo, parece muerto.\n");
    set_weight(1300);
    set_race_ob("/std/races/unknown");
}

void set_owner(string n, object ob) {
    owner = n;
    set_name("cuerpo");
    add_alias("corpse of " + n);
    add_alias("cuerpo de " + n);
    set_short("cuerpo de " + capitalize(n));
    if ( ob && ob->query_main_plural() )
	set_main_plural("cuerpos de "+capitalize(ob->query_main_plural()));
    else
	set_main_plural("cuerpos de "+capitalize(pluralize(n)));
    add_plural("cuerpos");
    add_plural("corpses");
    set_long("Esto es el cuerpo sin vida de "+capitalize(n)+".\n");
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
    int i;
    object *obs;
    decay -= 1;
    if(!race_name)
    {
	if(race_ob)
	    race_name = (string)race_ob->query_name();
	else race_name = "unknown";
    }
    if (decay == 7) {
	set_short("restos ligeramente descompuestos de "+capitalize(owner));
	set_main_plural("restos ligeramente descompuestos de "+capitalize(pluralize(owner)));
    }
    if (decay == 5) {
	set_short("restos putrefactos de "+race_name);
	set_main_plural("restos putrefactos de "+race_name);
	set_long("Esto es el cuerpo sin vida de un "+race_name+".\n");
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

void set_race_ob(string s)
{
    race_ob = s;
}

string query_race_ob()
{
    return race_ob;
}
/*
mixed find_inv_match(string s)
{
    string *bit;
    object bitobj, weap;
    int i,j;

    bit = race_ob->query_possible_bits(s);
    if (!bit || !sizeof(bit)) return all_inventory();

    bit -= bits_gone;
    if (!sizeof(bit)) return bit;

    weap = (object) this_player()->query_weapon();
    if(!weap) {
	write("No puedes cotar trozos de un cuerpo con tus manos desnudas.\n");
	return ({ });
    } else if(!weap->id("dagger") && !weap->id("knife")) {
	write("Solo puedes cortar cosas con un cuchillo o una daga.\n");
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
	set_long(query_long() + "Esta decapitado.\n");
	set_short("cadaver decapitado de " + capitalize(owner));
    }
    if (environment())
	bitobj->move(environment());
    return ({ bitobj });
}
*/

/* this for formatting of objects sake */
/*
object *query_armours() { return armours + ({ }); }
void set_armours(object *arm) { armours = arm; }
void remove_armour(object arm) { armours -= ({ arm }); }


object query_weapon() { return weapon; }
void set_weapon(object wpn) { weapon = wpn; }
void unwield_weapon(object wpn) { if(weapon == wpn) weapon = 0; }
*/

string query_possessive() { return "su"; }

/* Converted from call_outs to heartbeats by Baldrick. after a look at Aragorns
   code on RD sept '93 */

void heart_beat()
{
    decay();
} /* void heartbeat */
