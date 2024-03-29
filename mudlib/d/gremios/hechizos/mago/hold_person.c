/*** Wonderflug did this.  Really.  But he won't admit to it so don't ask ***/

#include "tweaks.h"

#define HOLD_SHADOW "/d/gremios/hechizos/cleric/hold_person_sh.c"

inherit "/d/gremios/hechizos/base.c";

void setup()
{
  set_spell_name("Paralizar persona");
  set_spell_level(5);
  set_sphere("combat");

  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);

  set_help_desc("This spell wraps the target in invisible bonds, preventing "
    "them from attacking. The spell lasts one round per three levels of " 
    "the caster.  Clerics of Cyrcia get 1.5 times the duration."
    "Strong targets will be able to struggle away slowly.");

  set_gp_cost(HOLD_COST);
  set_casting_time(1);
  set_rounds( ({ "round1" }) );
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int j;
  int resist;
  int theroll;
  int duration, level, duration_bon;
  object shad;
    int basetarget, basecaster;

  if (!target)
  {
    tell_object(caster, "There is nobody of that name here.\n");
    return -1;
  }

  if ( target->query_time_spell() )
  {
    target->dispell_time_spell();
    return 0;
  }

  if ( target->query_hold_spell() || target->query_pacify_spell() )
  {
    tell_object(caster,"Your target is already incapacitated.\n");
    return -1;
  }

  
  // New Saving throw by Khelben
/*      basecaster = caster->query_level()+caster->query_wis();
      if( caster->query_guild_name() == "Cyrcia" )
         basecaster = basecaster + 10;*/
	basecaster += 10;
  if ( target->query_int() > target->query_wis() )
      basetarget = target->query_level()+target->query_int();
  else
      basetarget = target->query_level()+target->query_wis();

  // Getting Tweaked....Roan 9/95 
  // adding check for magic resistance 
  resist = (int)target->query_property("magical");
  theroll = random(100);
  if (theroll < resist || 
               basetarget + 5 + random(10) > basecaster + random(10) )
  {
    if(!quiet)
    {
    tell_room(environment(caster), caster->query_cap_name()+
      " chants, 'amri xeno haltem'.\n", caster);
    tell_object(caster, "You chant, 'amri xeno haltem'.\n");
    tell_object(caster, target->query_cap_name()+" resists the effects "
      "of your spell!\n");
    tell_object(target, "You resist the effects of the spell!\n");
    tell_room(environment(caster), target->query_cap_name()+" resists "
      "effects of the spell.\n", ({ caster, target }) );
    }
    caster->attack_by(target);  // Hey, he tried to hold me, I'll kill him.
    return 0;
  }

  if ( !quiet )
  {
    tell_room(environment(caster), caster->query_cap_name()+
      " chants, 'amri xeno haltem'.\n", caster);
    tell_object(caster, "You chant, 'amri xeno haltem'.\n");
  }

  tell_object(caster, "You wrap "+target->query_cap_name()+
    " in bonds of invisible force.\n");
  tell_object(target, "You feel invisible bonds surround you, stopping "
    "your every movement.\n"); 
    tell_room(environment(caster), caster->query_cap_name()+
      " finishes a spell with a gesture at "+target->query_cap_name()+
      ", and "+target->query_pronoun()+" starts \nto struggle against "
      "invisible bonds.\n",
      ({ caster, target}) ); 

  level = (int)caster->query_level();

  duration_bon = 0;
  if ( (string)caster->query_guild_name() == "Cyrcia" )
    duration_bon = level*HOLD_DURATION_BONUS;

  duration = duration_bon + (level*HOLD_DURATION_LEVELX);
  j = cleric_fix_damage(caster, target, duration, "magical");
  target->add_timed_property("hold_person_on", 1, j);
  target->add_timed_property("nocast",1, j);
  target->add_timed_property("noguild",1,j);
  
  shad = clone_object(HOLD_SHADOW);
  shad->setup_shadow(target, caster); 
  target->add_extra_look(shad);
  target->attack_by(caster);

  return 0;
}
