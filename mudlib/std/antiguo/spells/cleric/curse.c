/*** Curse Spell ***/
/*** Created by Wonderflug, dare I associate myself with this ? ***/
 
inherit "/std/spells/base.c";
 
void setup()
{
  set_spell_name("Curse");
  set_spell_level(1);
  set_sphere("all");

  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);

  set_help_desc("This spell curses the target by -1 to hit in battle for "
    "a limited duration.");

  set_gp_cost(2);
  set_casting_time(1);
  set_rounds( ({ "round1" }) );
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int level;
 
  if ( wrong_alignment(caster) )
  {
    punish_align(caster);
    return -1;
  }

  if (!target)
  {
    tell_object(caster,
      "Your spell failed ... there is no one of that name here.\n");
    return -1;
  }
 
  if (target->query_property("clericcursed"))
  {
    tell_object(caster,
      "The target is already under the effects of a Curse.\n");
    return -1;
  }
 
  if ( !quiet )
  {
    tell_room(environment(caster),(string)caster->query_cap_name()+
      " chants, 'mali umanos'.\n", ({target,caster}));
    tell_object(target, "You chant, 'mali umanos'.\n");
  }
 
  if(target == caster)
  {
    tell_object(target, "You Curse yourself.  Bright idea.\n");
    tell_room(environment(caster),(string)caster->query_cap_name()+
      " casts a spell upon "+target->query_objective()+"self.\n",target);
  }   
  else
  {
    tell_object(target, (string)caster->query_cap_name()+
      " touchs you muttering a nasty curse!\n");
       
    tell_object(caster, "You touch "+
      (string)target->query_cap_name() + " while muttering a nasty curse!\n");
       
    tell_room(environment(caster),(string)caster->query_cap_name()+
      " touches "+target->query_cap_name()+" while muttering nastily.\n",
      ({target,caster}) );
  }
 
  level = (int)caster->query_level();
 
  target->adjust_tmp_tohit_bon(-10);
  target->add_static_property("clericcursed", 1);
  target->attack_by(caster);
 
  call_out("wear_off",100+(level*10),target);
  return 0;
}
 
void wear_off(object target)
{
  if(target)
  {
   target->adjust_tmp_tohit_bon(10);
   target->remove_static_property("clericcursed");
   tell_object(target, "Your Curse thankfully wears off.\n");
  }
}


