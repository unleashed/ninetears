/*** Thorn Foot -- Druids Spell ***/
/*** By Wonderflug ***/

#include "tweaks.h"

inherit "/std/spells/base.c";

void setup()
{
  set_spell_name("Thorn Foot");
  set_spell_level(2);
  set_sphere("druid");

  set_target_type("one");
  set_range(2);

  set_help_desc("This spell will place a thorn unerringly into an opponent's "
    "foot.  The bethorned victim will suffer damage when trying to move "
    "until such a time as they remove the affliction at great pain to "
    "themselves.  Won't have much effect on an NPC.");

  set_gp_cost(THORN_GP);
  set_casting_time(3);
  set_rounds( ({ "round1", "round2", "round3" }) );
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  tell_object(caster, "You draw in power from the world for your "
    "enchantment.\n");
  tell_room(environment(caster), caster->query_cap_name()+" goes into "
    "an odd trance-like state.\n", caster);
  return 0;
}

int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
  tell_object(caster, "A very sharp looking thorn appears in the air "
    "before you.\n");
  tell_room(environment(caster), "A very sharp looking thorn appears "
    "in the air before "+caster->query_cap_name()+".\n", caster );
  return 0;
}

int round3(object caster, mixed target, mixed out_range, int time, int quiet)
{
  object thorn;

  if (!target )
  {
    tell_object(caster, "Your spell failed.. there is no one of "
      "that name here.\n");
    tell_room(environment(caster), caster->query_cap_name()+" comes "
      "out of the trance, points a finger, and the thorn lodges itself "
      "into a nearby rock.\n", caster);
    return -1;
  }

  if ( !quiet )
  {
    tell_object(caster, "You come out of the trance and guide the thorn to "+
      target->query_cap_name()+"'s foot.\n");
    tell_object(target, caster->query_cap_name()+" comes out of the trance "
      "and points at you.\n\nThe thorn comes streaking toward you and "
      "lodges itself deeply into your foot!\n\nYou scream in pain.\n");
    tell_room(environment(caster), "The thorn suddenly streaks toward "+
      target->query_cap_name()+" and lodges itself in "+
      target->query_possessive()+" foot.\n\n"+target->query_cap_name()+
      " howls in pain.\n", target );
  }
   target->attack_by(caster);

  target->adjust_hp(-random(MAXDAM),caster);
  thorn = clone_object(THORN);
  thorn->move(target);
  thorn->reset_drop();
  thorn->reset_get();
  thorn->set_spell(target);

  return 0;
}
