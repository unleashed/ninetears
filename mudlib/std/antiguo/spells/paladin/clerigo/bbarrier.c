/*** Blade Barrier ***/
/*** Created by Taniwha ***/
/*** ->base spell by Wonderflug ***/
 
#include "tweaks.h"

inherit "/std/spells/base.c";

void setup()
{
  set_spell_name("Blade Barrier");
  set_spell_level(6);
  set_sphere("guardian");

  set_target_type("none");
  set_range(0);
  set_line_of_sight_needed(0);

  set_help_extras(
    "Damage Type: Physical\n"
    "Saving Throw: Level Dexterity");
  set_help_desc("This spell will create a wall of blades around the caster."
    "Anyone in the room will take damage if they don't make the saving "
    "throw, and extra damage if they are attacking the caster. "
    "The spell lasts 1 round /level +3 , "
    "until it is dispelled, or until the caster dies or leaves the game. "
    "Also note the caster gets a 10* bonus save, not total immunity.");

  set_gp_cost(BBARIER_GP);
  set_casting_time(1);
  set_rounds( ({ "round1" }) );
}


int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  object ob;

  if ( caster->query_property("blade_barrier_cast") )
  {
    tell_object(caster, "You cannot bring forth another blade barrier "
      "so soon.\n");
    return -1;
  }

  if ( !quiet )
  {
    tell_object(caster, "You chant, 'Deus Clavius'.\n");
    tell_room(environment(caster),(string)caster->query_cap_name()+
      " chants, \"Deus Clavius\".\n", ({ caster }));
  }

  caster->add_timed_property("blade_barrier_cast", 1, 30);
  ob = clone_object(SPELLS "blader.c");
  ob->move(environment(caster));
  ob->set_spell(caster, 3+(int)caster->query_level());
  tell_room(environment(caster),
    "The ground rips open and a wall of blades springs up!\n", ({ }) );
}


