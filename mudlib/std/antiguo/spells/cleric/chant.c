/*** Chant Spell ***/
/*** Created by Eerevann Tokani ***/
/*** Changed Prayer to Chant, Caanan ***/
/*** ->base spell, Wonderflug ***/
 
inherit "/std/spells/base.c";

void setup()
{
  set_spell_name("Chant");
  set_spell_level(3);
  set_sphere("combat");

  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);

  set_help_desc("This spell gives the target a penalty to hit and damage in "
    "battle for a limited duration.  This spell is cumulative with "
    "a Curse spell.");

  set_gp_cost(6);
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
 
  if (target->query_property("chant_on"))
  {
    tell_object(caster, 
      "The target is already under the effects of a Chant.\n");
    return -1;
  }
 
 
  if ( !quiet )
  {
    tell_room(environment(caster),(string)caster->query_cap_name()+
      " chants, 'acerbace unos baletis'.\n", ({target,caster}));
    tell_object(caster, "You chant, 'acerbace unos baletis'.\n");
  }
 
  if(target == caster)
  {
    tell_object(caster, "You cast a Chant upon yourself.\n");
    tell_room(environment(caster),(string)caster->query_cap_name()+
      " summons a Chant of Battle against "+target->query_objective()+
      "self.\n", target);
  }
  else
  {
 
    tell_object(target, (string)caster->query_cap_name()+
      " hisses at you summoning a Chant of Battle.\n");
    tell_object(caster, "You hiss at "+
      (string)target->query_cap_name() + " summoning a Chant of Battle "
      "against "+target->query_objective()+".\n");
    tell_room(environment(caster),(string)caster->query_cap_name()+
      " hisses at "+target->query_cap_name()+" giving a harsh chant.\n",
      ({target,caster}) );
  }
 
  target->add_static_property("chant_on", 1);
 
  target->adjust_tmp_tohit_bon(-20);
  target->adjust_tmp_damage_bon(-2);
  target->attack_by(caster);
 
  level = (int)caster->query_level();
  call_out("wear_off",200+(level*5),target);
  return 0;
}
 
void wear_off(object target)
{
  if(target)
  {
    target->adjust_tmp_tohit_bon(20);
    target->adjust_tmp_damage_bon(2);
    target->remote_static_property("chant_on");
    tell_object(target, "The Chant of Battle wears off.\n");
  }
}
