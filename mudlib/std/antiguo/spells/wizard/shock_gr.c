/*** Shocking Grasp Spell ***/
/*** Created by Eerevann Tokani ***/


#define TYPE "electrical"
#define SIZE_OF_DICE 8

inherit "/std/spells/base.c";

void setup()
{
  set_spell_name("Shocking Grasp");
  set_school("alteration");
  set_spell_level(1);

  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);

  set_help_extras(
    "Damage Type: " TYPE "\n"
    "Saving Throw: None");
  set_help_desc("When cast the casters hands become electrically charged.  "
    "The caster then touches the target for damage.  The damage done is "
    "1d8 + 1 point per level of the caster.\n");
 
  set_gp_cost(2);
  set_casting_time(1);
  set_rounds( ({ "round1" }) );
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int damage;
  int level;

  if ( !target )
  {
    tell_object(caster,
      "Your spell failed ... there is no one of that name here.\n");
    return -1;
  }

  if(target == caster)
  { 
    tell_object(caster, "Wouldn't that be suicide?\n");
    tell_room(environment(caster), (string)caster->query_cap_name()+
      " stops casting.\n", caster);
  }
    
  if ( !quiet )
  {
    tell_room(environment(caster), caster->query_cap_name()+
      " chants, 'hanz ow xlxyx'.\n", ({caster}));
    tell_object(caster, "You chant, 'hanz ow xlxyx '.\n");
  }

  target = check_melee_protector(target, caster);

  tell_object(target, "A burst of electricity jolts you from "+
    caster->query_cap_name()+"'s touch.\n");
   
  tell_object(caster, "You cast Shocking Grasp at "+
    (string)target->query_cap_name() + ".\n");
   
  tell_room(environment(caster), caster->query_cap_name()+
    " finishes a spell and touches "+target->query_cap_name()+
    " with a shocking grasp.\n",
    ({target,caster}) );


  level = (int)caster->query_level();
  damage = random(SIZE_OF_DICE) + 1 + level;
   damage = wiz_fix_damage(caster,target,damage,TYPE);
  target->spell_damage(target, damage, TYPE, caster);

  target->attack_by(caster);

  return 0;
}
