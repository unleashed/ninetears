/*** Haste ***/
/*** By Wonderflug ***/

#include "tweaks.h"

#define HASTE_DURATION_LEVEL 1
#define HASTE_SHADOW "/std/spells/bards/haste_sh.c"

inherit "/std/spells/base.c";

void setup() 
{
  set_spell_name("Haste");
  set_spell_level(4);
  set_school("alteration");

  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);

  set_help_desc("This spell alters time for the target.  In particular, it "
    "will be able to attack twice as often, and any spells cast on "
    "it will last shorter than normal.  The effects last one "
    "round per 2 levels of the caster.");

  set_gp_cost(10);
  set_casting_time(1);
  set_rounds( ({ "round1" }) );
}



int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  object shadow;
  int duration;

  if ( !target )
  {
    tell_object(caster, 
      "Your spell failed ... there is nobody of that name here.\n");
    return -1;
  }

  /* Destruct any current slow */
  if ( target->query_slow_spell() )
  {
    target->dispell_time_spell();
    return 1;
  }

  /* Check for a haste or other time spell */
  if ( target->query_time_spell() )
  {
    tell_object(caster, "Your target is already Hasted.\n");
    return -1;
  }

  /* Don't want these two at once I don't think.  */
  if ( target->query_hold_spell() || target->query_pacify_spell() )
  {
    tell_object(caster, "You cannot Haste that target right now.\n");
    return -1;
  }

  if ( !quiet )
  {
    tell_room(environment(caster), caster->query_cap_name()+
      " sings:\n\n"
      "   Step lively, on your feet, important business must we meet;\n"
      "   Run on, run ho, unto the Sword Sea by the morrow.\n"
      "   If Sherif rises from his bed, then he'll know just what we did;\n"
      "   Then his daughter and his sheep we'll join in sorrow.\n\n",
      caster);
    tell_object(caster,
      "You sing:\n\n"
      "   Step lively, on your feet, important business must we meet;\n"
      "   Run on, run ho, unto the Sword Sea by the morrow.\n"
      "   If Sherif rises from his bed, then he'll know just what we did;\n"
      "   Then his daughter and his sheep we'll join in sorrow.\n\n");
  }

  tell_object(target, "You feel your pulse quicken and you seem to be moving "
    "much faster than you were.\n");
  tell_room(environment(caster), caster->query_cap_name()+
    " gestures at "+target->query_cap_name()+", and "+
    target->query_possessive()+" movements speed up.\n",
    ({ caster, target}) ); 

  duration = ((int)caster->query_level()*HASTE_DURATION_LEVEL);
  // Wonderflug 96, magic resistance shortens the spell muhahaha.
  duration = wiz_fix_damage(caster, target, duration, "magical");

  target->add_timed_property("haste_on", 1, duration);
  
  shadow = clone_object(HASTE_SHADOW);
  shadow->setup_shadow(target); 

  return 0;
}
