/*** Priest Light Spell ***/
/*** Revised by: Eerevann ***/
/*** ->base spell by Wonderflug ***/

inherit "/std/spells/base.c";

void setup()
{
  set_spell_name("Light");
  set_spell_level(1);
  set_sphere("sun");

  set_target_type("one");
  set_range(0);

  set_help_desc("This spell will create a small globe of light that is "
    "placed upon the target to help illuminate dark areas.  This spell must "
    "be cast on a target of some sort.  The spell has a limited duration.");

  set_gp_cost(2);
  set_casting_time(1);
  set_rounds( ({ "round1" }) );
}


int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int mod;
  
  if ( wrong_alignment(caster) )
  {
    punish_align(caster);
    return 0;
  }

  if(!target)
  {
    tell_object(caster, "Your light spell fizzles since you "
      "can't see it's intended target.\n");
    return -1;
  }

  if ( !quiet )
  {
    tell_object(caster, "You chant, 'illumin los'.\n");
    tell_room(environment(caster), caster->query_cap_name()+
      " chants, 'illumin los'.\n", caster);
  }

  if (target == caster)
  {
    tell_object(caster,"A globe of bright light starts floating near you.\n");
    tell_room(environment(caster),(string)caster->query_cap_name() +
      " raises his hands and a globe of light appears.\n", target);
  }
  else
  {
    tell_object(caster,"You cast light on "+
      (string)target->query_cap_name()+", who starts to glow with light.\n");
    tell_room(environment(caster),(string)caster->query_cap_name()+
      " mumbles something and "+(string)target->query_cap_name()+
      " starts to glow with light.\n", ({ caster, target }) );
    tell_object(target, (string)caster->query_cap_name()+
      " points at you and a globe of light appears in your hand.\n");
  }

  switch( caster->query_sphere_power("sun") )
  {
    case "major":
      mod = 50;
      break;
    case "minor":
      mod = 20;
      break;
    default:
      mod = 30;
  }

  target->set_light(60);
  call_out("wear_off", (int)caster->query_level()*mod, target);

  return 0;
}

void wear_off(object target)
{
  if(target)
  {
    target->set_light(0);
    tell_object(target,"Your globe of light disappears.\n");
    tell_room(environment(target),target->query_cap_name()+
      " stops glowing with light.\n",target);
  }
}
