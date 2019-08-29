/*** Priest Darkness Spell ***/
/*** Revised by: Eerevann ***/
/*** ->base spell by Wonderflug ***/

inherit "/std/spells/base.c";


void setup()
{
  set_spell_name("Darkness");
  set_spell_level(2);
  set_sphere("summoning");

  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);

  set_help_desc("This spell will create a small globe of darkness that is "
   "placed upon the target to help alleviate blinding light.  This spell "
   "must be cast on a target of some sort. The spell has a limited "
   "duration.");

  set_gp_cost(4);
  set_casting_time(1);
  set_rounds( ({ "round1" }) );
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int duration;

  if ( wrong_alignment(caster) )
  {
    punish_align(caster);
    return -1;
  }

  if(!target)
  {
    tell_object(caster, "Your darkness spell fizzles since you "
      "can't see it's intended target.\n");
    return -1;
  }

  switch( caster->query_sphere_level("summoning") )
  {
    case "minor":  
      duration = caster->query_level()*5;
      break;
    case "neutral": 
      duration = caster->query_level()*10;
      break;
    case "major": 
      duration = caster->query_level()*20;
      break;
    default: 
      duration = caster->query_level()*5;
  }

  if (target == caster)
  {
    tell_object(caster, "Darkness envelops you.\n");
    tell_room(environment(caster),(string)caster->query_cap_name() +
      " raises a hand and is enveloped in sudden darkness.\n", target);
  }
  else
  {
    tell_object(caster,"You cast a spell on "+
      (string)target->query_cap_name()+", who is shrouded in darkness.\n");
    tell_room(environment(caster),(string)caster->query_cap_name()+ 
      "mumbles something and "+(string)target->query_cap_name()+
      " is shrouded with darkness.\n", ({ caster, target }) );
    tell_object(target, (string)caster->query_cap_name()+
      " points at you and you are enveloped in darkness.\n");
  }

  target->set_light(-30);
  call_out("wear_off", duration, target);

  return 0;
}

void wear_off(object target)
{
  if(target)
  {
    target->set_light(0);
    tell_object(target,"The darkness surrounding you disappears.\n");
    tell_room(environment(target),target->query_cap_name()+" is startled "
      "as the surrounding darkness lifts.\n",target);
  }
}
