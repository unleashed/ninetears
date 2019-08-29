/*** Prayer Spell ***/
/*** Created by Eerevann Tokani ***/
/*** ->base spell by Wonderflug ***/

inherit "/std/spells/base.c";

void setup()
{
  set_spell_name("Prayer");
  set_spell_level(3);
  set_sphere("combat");

  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);

  set_help_desc("This spell grants the target a bonus to hit and damage in "
    "battle for a limited duration.  This spell is cumulative with "
    "a Bless spell.");

  set_gp_cost(6);
  set_casting_time(1);
  set_rounds( ({ "round1" }) );
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int level;

  if (!target)
  {
    tell_object(caster,
      "Your spell failed ... there is no one of that name here.\n");
    return -1;
  }
  if (target->query_property("prayer_on"))
  {
    tell_object(caster,
      "The target is already under the effects of a Prayer.\n");
    return 0;
  }
    
  if ( !quiet )
  {
    tell_room(environment(caster),(string)caster->query_cap_name()+
      " chants, 'amenis unos baletis'.\n", ({caster}));
    tell_object(caster, "You chant, 'amenis unos baletis'.\n");
  }
    
  if(target == caster)
  { 
    tell_object(target, "You cast a Prayer upon yourself.\n");
    tell_room(environment(caster),(string)caster->query_cap_name()+
      " chants a Prayer of Battle for "+target->query_objective()+
      "self.\n",caster);
   }
  else
  {
    tell_object(target, (string)caster->query_cap_name()+
      " kneels over you chanted a Prayer of Battle.\n");
    tell_object(caster, "You kneel over "+
      (string)target->query_cap_name() + " chanting a Prayer of Battle "
      "for "+target->query_objective()+".\n");
    tell_room(environment(caster),(string)caster->query_cap_name()+
      " kneels over "+target->query_cap_name()+" giving a harsh prayer.\n",
      ({target,caster}) );
  }
  
  target->add_static_property("prayer_on", 1);
  target->adjust_tmp_tohit_bon(20);
  target->adjust_tmp_damage_bon(1);  

  level = (int)caster->query_level();
  switch( caster->query_sphere_power("combat") )
  {
    case "minor":
      level -= 5;
      break;
    case "major":
      level += 5;
      break;
  }
  call_out("wear_off",100+(level*5),target);
  return 0;
}

void wear_off(object target)
{
  if(target)
  {
    target->adjust_tmp_tohit_bon(-20);
    target->adjust_tmp_damage_bon(-1);
    target->remove_static_property("prayer_on");
    tell_object(target, "Your Prayer of Battle wears off.\n");
  }
}
