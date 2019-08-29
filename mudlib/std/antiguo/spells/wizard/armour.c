/*** Armour Spell ***/
/*** Created by Eerevann Tokani ***/
/*** Rewritten to use base spell object by Wonderflug ***/


inherit "/std/spells/base.c";

void setup()
{
  set_spell_name("Armour");
  set_school("conjuration");
  set_spell_level(1);

  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);

  add_property_to_check("armour_on");

  set_help_desc("This spell conjures a glowing protective suit of armour "
    "that surrounds the target, granting a small armour class bonus for "
    "duration dependent on the level of the caster.");
  set_help_extras(0);

  set_casting_time(1);
  set_gp_cost(2);
  set_rounds( ({ "round1" }) );
}


int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int bonus;
  int level;
  int conj_bon;
  int duration_bon;

  level = (int)caster->query_level();
  if (!target)
  {
    tell_object(caster,
      "Your spell failed ... there is no one of that name here.\n");
    return -1;
  }
  
  if ( target->query_property("armour_on") )
  {
    tell_object(caster,
      "The target is already affected by an Armour spell.\n");
    return -1;
  }

  if ( !quiet )
  {
    tell_room(environment(caster),(string)caster->query_cap_name()+
      " chants, 'mior armanis'.\n", ({ target, caster }));
    tell_object(caster, "You chant, 'mior armanis'.\n");
  }

  if(target == caster)
  { 
    tell_object(target, "You feel a vague sense of protection.\n");
    tell_room(environment(caster), "A faint shimmering light glows around "
      +(string)caster->query_cap_name()+".\n",caster);
  }
  else
  {
    tell_object(target, "You feel a vague sense of protection.\n");
    tell_object(caster, "You cast Armour on "+
      (string)target->query_cap_name() + ".\n");
    tell_room(environment(caster),(string)caster->query_cap_name()+
      " makes a gesture at "+target->query_cap_name()+" as a faint "
      "shimmering light surrounds "+target->query_objective()+".\n",
      ({target,caster}) );
  }

  conj_bon = 0;
  duration_bon = 0;

  level = (int)caster->query_level();

  if(interactive(caster) && (string)caster->query_guild_name() == "conjurer")
  {
	conj_bon = (10*(level-1))/3;
	duration_bon = level*30;
  }

  bonus = 20 + conj_bon;

  target->adjust_tmp_ac_bon(bonus);
  target->add_extra_look(this_object());
  target->add_static_property("armour_on", 1);

  call_out("wear_off",(200+(level*20)+duration_bon), bonus, target);

  return 0;
}

void wear_off(int bonus, object target)
{
  if(target)
  {
    target->adjust_tmp_ac_bon(-bonus);
    tell_object(target, "You feel more vulnerable.\n");
    target->remove_extra_look(this_object());
    target->remove_static_property("armour_on");
  }
}

string extra_look()
{
  return "Is surrounded by a very faint, shimmering golden light.\n";
}
