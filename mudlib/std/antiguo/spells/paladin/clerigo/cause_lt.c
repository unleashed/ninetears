/*** Cause Light Wounds Spell ***/
/*** Created by Eerevann Tokani ***/
/*** ->base spell by Wonderflug ***/

inherit "/std/spells/base.c";

#define TYPE "magical"
#define save_type "magical"

void setup()
{
  set_spell_name("Cause Light Wounds");
  set_spell_level(1);
  set_sphere("healing");

  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);

  set_help_extras(
    "Damage Type: " TYPE "\n"
    "Saving Throw: None");
  set_help_desc("This spell will do 1-8 points of damage to an enemy "
    "of your choice.  The spell, once cast, requires the caster to touch the "
    "target.  If the touch misses, the spell's energy is wasted.");

  set_gp_cost(2);
  set_casting_time(1);
  set_rounds( ({ "round1" }) );
}


int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int damage;
  int ac_hit;

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

  if(target == caster)
  {
    tell_object(caster, "Wouldn't that be suicide?\n");
    tell_room(environment(caster), (string)caster->query_cap_name()+
      " stops casting.\n",caster);
    return -1;
  }

  if ( !quiet )
  {
    tell_room(environment(caster), (string)caster->query_cap_name()+
      " chants, 'magius elis harmei'.\n", ({target,caster}));
    tell_object(caster, "You chant, 'magius elis harmei'.\n");
  }

   
  ac_hit = (int)caster->query_thac0() - random(200) - 1;
  if((random((int)caster->query_thac0()) + target->query_total_ac()) > 0)
  {
    tell_object(target, (string)caster->query_cap_name()+
      " reaches out and touches you as minor cuts "
      "appear on you.\n");
    tell_object(caster, "You cast Cause Light Wounds and touch "+
      (string)target->query_cap_name() + " causing minor cuts.\n");
    tell_room(environment(caster), (string)caster->query_cap_name()+
      " casts a spell and touches "+target->query_cap_name()+" causing "
      "minor cuts.\n",
      ({target,caster}) );
  } 
  else 
  {
    tell_object(target, (string)caster->query_cap_name()+
      " reaches out and trys to touch you, missing.\n");
    tell_object(caster, "You cast Cause Light Wounds and try to touch "+
      (string)target->query_cap_name() + ", missing.\n");
    tell_room(environment(caster), (string)caster->query_cap_name()+
      " casts a spell and trys to touches "+target->query_cap_name()+
      ", missing.\n",
      ({target,caster}) );
    return 1;
  }
  


  damage = roll( 1, 8 );

  damage = cleric_fix_damage(caster,target,damage,save_type);
  target->adjust_hp(-damage);

  target->attack_by(caster);

  return 0;
}
