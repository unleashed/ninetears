/* Wall of Fire Object.  March 1995
 * This is the object for a wall of fire spell, actually a dead npc
 * that blocks the exit we've been given.
 * No doubt there are tremendous numbers of bugs here.  Should prolly give
 * xp to the caster for the damage done, but I'll let tani do that :)
 */

/* By Wonderflug */

#include "tweaks.h"
inherit "/std/spells/patch.c";
inherit "/obj/monster";

object mycaster;
int mycount;
string myexit;
string myalias;

int dispell_me()
{
  tell_room(ETO,"The wall of flame vanishes, leaving only a scattering of "
        "ashes and \na stench of burned sulphur on the air.\n",({ }));
  this_object()->dest_me();
  return 1;
}

string query_is_wall() { return myexit; }

void do_death(object ob) { }

int do_spell(string str, object hack);

void attack_by(object ob)
{
  ob->stop_fight(this_object());
  tell_room(ETO,(string)ob->query_cap_name()+
        " bravely, but futilely tries to attack a wall of fire.\n",
        ob);
  tell_object(ob, "You take leave of your senses, and attack a wall of "
        "fire.\n");
  do_spell("", ob);
}

void init()
{
  ::init();
  add_action("do_spell",myexit);
  add_action("do_spell", myalias);
  add_action("do_sneak", "sneak");
}

int do_spell(string str, object hack)
{
  object ob;
  int odds, damage;
  ob = hack ? hack : this_player();

  if(IMMORTLOCK) if(ob->query_creator())   return 0;

  if ((int)ob->query_property("dead")) return 0;
  if(find_living((string)ob->query_name()) )
  {
    if ((int)ob->query_level() < 5 )
    {
        tell_object(ob, "You approach the wall of fire but you feel "
          "too inexperienced \nto attempt to jump through it.  It's so "
          "HOT!\n");
        tell_room(ETO, ob->query_cap_name()+" goes near the wall of "
          "fire but looks scared and \nbacks away hurriedly.\n", ob);
        return 1;
    }
    if(ob == mycaster) return 0;
    else odds = (int) ob->query_level();
    switch(random(100)+odds )
    {
        case 0..50: /* halted, moderate damage */
          tell_object(ob, "You try and go through the wall of fire but "
            "only end up severely \nburning yourself before giving up.\n");
          tell_room(environment(ob), ob->query_cap_name()+" tries to go "
            "through the wall of fire but \nreappears with severe burns and "
            "in pain a few seconds later.\n");
          damage = random(WALLFIRE_FAIL_DAMAGE);
          damage += (int)mycaster->query_level();
          damage = cleric_fix_damage(mycaster, ob, damage, "fire");
          ob->adjust_hp(-damage,this_object());
          return 1;
        case 51..1000: /* make it, lots of damage */
          tell_object(ob, "\nYou scream in pain as you run through the "
            "wall of fire, but arrive \non the other side..\n\n");
          tell_room(environment(ob), "\n"+ob->query_cap_name()+" screams "
            "horribly as "+ob->query_pronoun()+" runs through a wall of "
            "fire.\n");
          damage = random(WALLFIRE_SUCCESS_DAMAGE);
          damage += (int)mycaster->query_level();
          damage = cleric_fix_damage(mycaster, ob, damage, "fire");
          ob->adjust_hp(-damage,this_object());
          return 0;
    }

  }
return 1;
}

int do_sneak( string str )
{
  object ob;
  int damage;

  ob = this_player();

  if ( str != myexit && str != myalias )
        return 0;

  tell_object( ob, "Sneaking, being in general a slow, slinking kind of "
        "movement, takes \na somewhat long time to cover a stretch of "
        "ground.  Since you've tried \nto sneak through a wall of fire, "
        "you get exposed to the flames several \ntimes over what you "
        "normally would.  Maybe you shouldn't be so \nstupid next time, "
        "and watch where you sneak.\n");
  tell_room(environment(ob), "You notice "+ob->query_cap_name()+" trying "
        "to SNEAK through the wall of \nfire.  Shaking your head at "+
        ob->query_possessive()+" stupidity, you try and drown out \nthe "
        "screams of pain that follow.\n", ob);
  damage = random(WALLFIRE_SUCCESS_DAMAGE)*3;
  damage += (int)mycaster->query_level()*3;
  damage = cleric_fix_damage(mycaster,ob,damage,"fire");
  ob->adjust_hp(-damage,this_object());
  return 1;
}


void set_spell(object ob, string exit)
{
  mycaster = ob;
  mycount = (int)ob->query_level()*WALLFIRE_DURATION_LEVEL;
  myexit = exit;
  switch( exit )
  {
        case "north" : myalias = "n"; break;
        case "south" : myalias = "s"; break;
        case "east" : myalias = "e"; break;
        case "west" : myalias = "w"; break;
        case "northwest" : myalias = "nw"; break;
        case "northeast" : myalias = "ne"; break;
        case "southwest" : myalias = "sw"; break;
        case "southeast" : myalias = "se"; break;
        case "up" : myalias = "u"; break;
        case "down" : myalias = "d"; break;
	default : myalias = "blubberdeflubber";
  }
  set_short("Wall of fire blocking the "+exit+" exit");
  set_long("This is a massive wall of white flames entirely covering the "+
        exit+" exit.  There's no way past it without running through "
        "it.  You can feel the heat rolling off the wall and try to "
        "keep your distance from it.\n");
}

void setup()
{
  set_name("wall of fire");
  set_short("wall of fire");
  set_race("monster");
  add_alias("wall");
  set_gender(0);
  add_property("dead",1);
  set_long("\nA massive wall of flame entirely obscuring an exit."
        "\n");
  set_spell(this_object(),"blah");
}

void heart_beat()
{
  if ( (int)this_object()->query_hb_counter() > mycount )
  {
	tell_room(ETO, "The wall of fire dies off.\n");
        this_object()->dest_me();
  }
  else return ::heart_beat();

}

