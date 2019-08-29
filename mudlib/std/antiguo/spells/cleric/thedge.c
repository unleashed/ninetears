/*** Thorn Hedge ***/
/*** Created by Taniwha ***/
/*** -> base spell, Wonderflug ***/
 
#include "tweaks.h"

inherit "/std/spells/base.c";

void setup()
{
  set_spell_name("Thorn Hedge");
  set_spell_level(THEDGE_LEVELX);
  set_sphere("plant");

  set_target_type("none");
  set_range(0);
 
  set_help_extras(
    "Damage Type: Physical\n"
    "Saving Throw: Level Dexterity");
  set_help_desc("This spell will create a hedge of thorns in a room."
    "Anyone in the room will take damage if they don't make the saving "
    "throw, and extra damage if they are attacking the caster. "
    "The spell lasts 1 round /level +3 , until it is dispelled, or until "
    "the caster dies or leaves the game. Also note the caster gets a 10* "
    "bonus save, not total immunity.");

  set_gp_cost(THEDGE_GP);
  set_casting_time(2);
  set_rounds(
    ({
      ({
        "Small seedlike pinpoints of light scatter over the area at your "
          "bidding.\n",
        "Small seedlike pinpoints of light appear and scatter over the area.\n"
      }),
      "round2"
    }) );
}

int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
  object ob;

  if ( caster->query_property("thorn_hedge_cast") )
  {
    tell_object(caster, "Your spell fizzles for some reason.\n");
    tell_room(environment(caster), "The light-seeds fall to the ground "
      "and disperse harmlessly.\n", ({ }) );
    return -1;
  }
 
  if ( !quiet )
  {
    tell_object(caster, "You chant, 'Deus Topiary'.\n");
    tell_room(environment(caster), caster->query_cap_name()+
      " chants, 'Deus Topiary'.\n.", ({ caster }) );
  }

  ob = clone_object(SPELLS+"thorns.c");
  ob->move(environment(caster));
  ob->set_spell(caster, 3+(int)caster->query_level());

  caster->add_timed_property("thorn_hedge_cast", 1, THEDGE_LOCKOUT);

  tell_room(environment(caster),
    "Wherever the light-seeds land, vines suddenly grow "
    "at incredible speed, \nforming a dense thorn covered hedge!\n",
    ({ }) );

  return 0;
}
