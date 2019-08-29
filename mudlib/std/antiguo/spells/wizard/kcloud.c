/*** Cloud Kill ***/
/*** Created by Taniwha ***/
/*** Adapted to base object by Wonderflug ***/

inherit "/std/spells/base.c";
 
#include "tweaks.h"
#define LOCKOUT "cloud_kill_cast"

void setup()
{
  set_spell_name("Cloud Kill");
  set_school("invocation");
  set_spell_level(CLOUD_KILL_LEVEL);

  set_target_type("none");
  set_range(0);
  set_line_of_sight_needed(0);

  add_property_to_check(LOCKOUT);

  set_help_desc("This spell will fill a room with a lethal cloud of gas. "
    "Players other than the caster are forced to flee.  The cloud lasts "
    "1 round/level, until it is dispelled, or until the caster dies or "
    "leaves the game.  Also note the caster gets a large bonus to save, "
    "not total immunity.  The spell will earn you kill XP IF you stay in "
    "the room.");
  set_help_extras(
    "Damage Type: Poison\n"
    "Saving Throw: Level + Resist Poison");

  set_casting_time(1);
  set_gp_cost(CLOUD_KILL_GP);
  set_rounds( ({ "round1" }) );
}

  

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  object ob;

  if ( !quiet )
  {
    tell_object(caster, "You chant \"Cumulous letum\".\n");
    tell_room(environment(caster), caster->query_cap_name()+
      " chants \"Cumulous letum\".\n", caster);
  }

  tell_room(environment(caster),
    "A cloud of deadly vapour fills the room!\n",({ }) );

  caster->add_timed_property(LOCKOUT,1,CLOUD_KILL_LOCKOUT);

  ob = clone_object(SPELLS+"ckiller.c");
  ob->move(environment(caster));
  ob->set_spell(caster,(int)caster->query_level());

  return 1;
}


