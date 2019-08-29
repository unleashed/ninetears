/*** Stinking cloud ***/
/*** Created by Taniwha ***/
/*** Adapted to base spell by Wonderflug ***/

#include "tweaks.h"
#define LOCKOUT "stinking_cloud_cast"

inherit "/std/spells/base.c";

void setup()
{
  set_spell_name("Stinking Cloud");
  set_spell_level(STINK_LEVEL);
  set_school("invocation");

  set_target_type("none");
  set_range(0);
  set_line_of_sight_needed(0);

  add_property_to_check(LOCKOUT);

  set_help_extras(
    "Damage Type: Poison\n"
    "Saving Throw: Level Constitution and Resist Poison");
  set_help_desc("This spell will fill a room with a cloud of nauseating "
    "vapour.  Effects are varied, ranging from none to vomiting. "
    "The spell lasts 1 round/level + 2, "
    "until it is dispelled, or until the caster dies or leaves the game. "
    "Also note the caster gets a 10* bonus save, not total immunity.");

  set_gp_cost(STINK_GP);
  set_casting_time(1);
  set_rounds( ({ "round1" }) );
}


int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  object ob;

  if ( !quiet )
  {
    tell_room(environment(caster),(string)caster->query_cap_name()+
      " chants, 'cumulous nasueous'.\n", ({ caster }));
    tell_object(caster, "You chant, 'cumulous nasueous'.\n");
  }

  caster->add_timed_property(LOCKOUT,1,STINK_LOCKOUT);
  ob = clone_object(SPELLS+"stinker.c");
  ob->move(environment(caster));
  ob->set_spell(caster, (int)caster->query_level());
  tell_room(environment(caster),"A stinking cloud fills the room!\n",({ }) );
}
