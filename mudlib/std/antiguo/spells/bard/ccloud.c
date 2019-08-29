/*** Cloud of confusion ***/
/*** Created by Taniwha ***/
/*** Adapted to base spell by Wonderflug ***/
 
inherit "/std/spells/base.c";

#include "tweaks.h"
#define LOCKOUT "cloud_of_confuse_cast"

void setup()
{
  set_spell_name("Cloud of Confusion");
  set_school("invocation");
  set_spell_level(CONFUSE_LEVEL);

  set_target_type("none");
  set_range(0);
  set_line_of_sight_needed(0);

  add_property_to_check(LOCKOUT);

  set_help_desc("This spell will fill a room with a cloud of narcotic "
    "vapour.  Effects are varied, and the cloud lasts for 1 round/level "
    "+ 2, until it is dispelled, or until the caster dies or leaves the "
    "game.  Also note the caster gets a great bonus to save, not total "
    "immunity to the effects.");
  set_help_extras("Saving Throw: Level");

  set_casting_time(1);
  set_gp_cost(CONFUSE_GP);
  set_rounds( ({ "round1" }) );
}



int round1(object caster, mixed target, mixed out, int time, int quiet)
{
  object ob;

  if ( !quiet )
  {
    tell_object(caster, "You chant \"Cumulous confendre\".\n");
    tell_room(environment(caster), caster->query_cap_name()+
      "chants \"Cumulous confendre\".\n", caster);
  }

  caster->add_timed_property(LOCKOUT,1,CONFUSE_LOCKOUT);

  ob = clone_object(SPELLS+"confuse.c");
  ob->move(environment(caster));
  ob->set_spell(caster, 2+(int)caster->query_level());
  tell_room(environment(caster),
    "A cloud of narcotic vapour fills the room!\n",({ }) );

  return 1;
}


