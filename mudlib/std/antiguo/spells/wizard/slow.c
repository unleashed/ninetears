/*** Slow ***/
/*** By Wonderflug ***/

#include "tweaks.h"

#define SLOW_DURATION_LEVEL 1
#define SLOW_SHADOW "/std/spells/wizard/slow_sh.c"

inherit "/std/spells/base.c";

void setup()
{
  set_spell_name("Slow");
  set_spell_level(4);
  set_school("alteration");

  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);

  set_help_desc("This spell slows time for the target.  In particular, it "
	"will not be able to attack as often, and any spells cast on "
	"it will last longer than normal.  The slow itself lasts one "
	"round per level of the caster.");

  set_gp_cost(10);
  set_casting_time(1);
  set_rounds( ({ "round1" }) );
}


int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int duration;
  object ob;

  if ( !target )
  {
    tell_object(caster, 
      "Your spell failed ... there is nobody of that name here.\n");
    return -1;
  }

  if ( target->query_haste_spell() )
  {
    target->dispell_time_spell();
    return 0;
  }

  if ( target->query_slow_spell() )
  {
    tell_object(caster,"Your target has already been Slowed.\n");
    return -1;
  }

  if ( target->query_hold_spell() || target->query_pacify_spell() )
  {
    tell_object(caster,"An enchantment already on the target disrupts "
      "your spell.\n");
    return -1;
  }

  if ( !quiet )
  {
    tell_room(environment(caster), caster->query_cap_name()+
      " chants, 'temporis laggen'.\n", 
      caster);
    tell_object(caster, "You chant, 'temporis laggen'.\n");
  }

  tell_object(caster, "You cast Slow on "+ target->query_cap_name()+".\n");
  tell_object(target, "You feel time turn to mush around you, slowing "
    "your every movement.\n"); 
  tell_room(environment(caster), caster->query_cap_name()+
      " finishes a spell with a gesture at "+target->query_cap_name()+
      ", and "+target->query_possessive()+" movements slow down.\n",
      ({ caster, target}) ); 

  duration = ((int)caster->query_level()*SLOW_DURATION_LEVEL);
  duration = wiz_fix_damage(caster, target, duration, "magical");
  target->add_timed_property("slow_on", 1, duration);
  
  ob = clone_object(SLOW_SHADOW);
  ob->setup_shadow(target); 

  return 0;
}
