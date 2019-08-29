/*** SILENCE ***/
/*** Created by Wonderflug ***/
 

inherit "/std/spells/base.c";

#include "tweaks.h"

void setup()
{
  set_spell_name("Silence");
  set_sphere("charm");
  set_spell_level(SILENCE_LEVELX);

  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);

  set_help_desc("This spell makes the recipient unable to speak, shout, or "
    "otherwise use his/her vocal chords.  Most importantly, the "
    "target will not be able to cast spells.  The spell lasts two "
    "rounds per level of the caster.");

  set_gp_cost(SILENCE_GP);
  set_casting_time(1);
  set_rounds( ({ "round1" }) );
}



int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  object ob;

  if ( !target )
  {
    tell_object(caster, 
      "Your spell failed ... there is nobody of that name here.\n");
    return -1;
  }

  if ( target->query_silence_spell() )
  {
    tell_object(caster, "Your target is already silenced.\n");
    return -1;
  }

  if ( !quiet )
  {
    tell_object(caster, "You chant, 'solus paqua quietum'.\n\n");
    tell_room(environment(caster),(string)caster->query_cap_name()+
      " chants, 'solus paqua quietum'.\n\n", ({ caster }));
  }

  /* saving throw first */
  if ( (int)caster->query_int() < random((int)target->query_level()) )
  {
    tell_room(environment(caster), caster->query_cap_name()+
      " completes the spell, but nothing seems to happen.\n",
      ({target, caster}) );
    tell_object(target, caster->query_cap_name()+
      " completes the spell, then stares intently at you, as if "
      "\nwondering why nothing happened.\n");
    tell_object(caster, "You complete the spell, but "
      "apparently "+target->query_cap_name()+" is unaffected.\n");

    if ( !interactive(target) )
      target->attack_by(caster);

    return 0;
  }

  ob = clone_object(SPELLS+"silence_sh.c");
  ob->setup_shadow(target);
  target->add_extra_look(ob);
  target->add_timed_property("silence_on",1,(int)caster->query_level()*2);
  target->add_timed_property("nocast", 1, caster->query_level()*2);

  tell_room(environment(caster),caster->query_cap_name()+" gestures and "+
    target->query_cap_name()+"screams silently.\n",
    ({ caster, target }) );
  tell_object(caster,"You silence "+target->query_cap_name()+", "
    "and "+target->query_pronoun()+" screams silently at you.\n");
  tell_object(target,caster->query_cap_name()+" gestures, "
    "and you feel a tightness in your throat, and you're unable to "
    "say a thing!\n");

  if ( !interactive(target) )
    target->attack_by(caster);

  return 0;
}
