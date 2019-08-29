/*** Darkness spell ***/
/*** By someone, adapted to base spell object by Wonderflug ***/

inherit "/std/spells/base.c";

void setup()
{
  set_spell_name("Darkness");
  set_school("alteration");
  set_spell_level(1);

  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);

  set_help_desc("This spell creates a well of darkness, swallowing the light "
    "around the target, letting them see in too-bright rooms.\n");
  set_help_extras(0);

  set_casting_time(1);
  set_gp_cost(2);
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
      " chants, 'maguis xeno lios'.\n", ({caster}));
    tell_object(caster, "You chant, 'magius xeno lios'.\n");
  }

  if ( target == caster )
  {
    tell_object(caster, "The world seems to darken around you.\n");
    tell_room(environment(caster),(string)caster->query_cap_name()+
      " is obscured by a well of darkness.\n",caster);
  }
  else
  {
    tell_object(target, "The world seems to darken around you.\n");
   
    tell_object(caster, "You cast Darkness on "+
      (string)target->query_cap_name() + ".\n");
   
    tell_room(environment(caster),(string)caster->query_cap_name()+
      " casts a well of darkness upon "+target->query_cap_name()+".\n",
      ({target,caster}) );
  }

  target->set_light(-30);
  call_out("wear_off",100+((target->query_level())+400), target);

  return 0;
}

void wear_off(object target)
{
  if (!target) 
    return ;
  target->set_light(0);
  tell_object(target,"You blink as your well of darkness disappears.\n");
  tell_room(environment(target), target->query_cap_name()+
    "'s well of darkness disappears.\n",target);
}
