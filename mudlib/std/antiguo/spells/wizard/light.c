/*** Light Spell ***/
/*** Created by Eerevann Tokani ***/
/*** To base spell, Wonderflug 96 ***/


#define SP_NAME "Light"
#define GP_COST 2
#define SPELLTYPE "misc"

inherit "/std/spells/base.c";

void setup()
{
  set_spell_name("Light");
  set_school("alteration");
  set_spell_level(1);

  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);

  set_help_desc("This spell creates light allowing you or your target "
    "to see in dark rooms.");

  set_gp_cost(2);
  set_casting_time(1);
  set_rounds( ({ "round1" }) );
 
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{

  if (!target)
  {
    tell_object(caster,
      "Your spell failed ... there is no one of that name here.\n");
    return -1;
  }
   
  if ( !quiet )
  {
    tell_room(environment(caster),(string)caster->query_cap_name()+
      " chants, 'magius lios'.\n", ({caster}));
    tell_object(target, "You chant, 'magius lios'.\n");
  }
    
  if(target == caster)
  { 

    tell_object(target, "You cast Light upon yourself.\n");
    tell_room(environment(caster),(string)caster->query_cap_name()+
      " casts a spell upon "+target->query_objective()+"self.\n",target);
  }
  else
  {
    tell_object(target, (string)caster->query_cap_name() +
      " casts Light on you.\n");
   
    tell_object(caster, "You cast Light on "+
      (string)target->query_cap_name() + ".\n");
   
    tell_room(environment(caster),(string)caster->query_cap_name()+
      " casts a light upon "+target->query_cap_name()+".\n",
      ({target,caster}) );
  }

   
  target->set_light(60);
  call_out("wear_off", 100+((caster->query_level())+400), target);

  return 0;
}

void wear_off(object target)
{
  if (!target) 
    return ;
  target->set_light(0);
  tell_object(target,"Your globe of light disappears.\n");
  tell_room(environment(target),target->query_cap_name()+
    "'s globe of light disappears.\n",target);
}
