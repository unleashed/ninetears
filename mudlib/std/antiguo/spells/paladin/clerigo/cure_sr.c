/*** Cure Serious Wounds Spell ***/
/*** Created by Eerevann Tokani ***/
/*** ->base spell by Wonderflug ***/

inherit "/std/spells/base.c";

#define SP_NAME "Cure Serious Wounds"
#define GP_COST 8
#define SPELLTYPE "curing"
#define TYPE "magical"
#define SIZE_OF_DICE 8
#define save_type "magical"

void setup()
{
  set_spell_name("Cure Serious Wounds");
  set_spell_level(3);
  set_sphere("healing");

  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);

  set_help_desc("This spell will cure a large amount of damage, and can "
    "be a life saver.  Clerics whose dieties have greater power in the "
    "sphere of healing will get better results with this spell.");

  set_gp_cost(6);
  set_casting_time(1);
  set_rounds( ({ "round1" }) );
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int damage;

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

  if ( !quiet )
  {
    tell_room(environment(caster),(string)caster->query_cap_name()+
      " chants, 'magius selirs curis'.\n", ({target,caster}));
    tell_object(caster, "You chant, 'magius selirs curis'.\n");
  }
    
  if(target == caster)
  { 
    tell_object(target, "You cure some of your wounds.\n");
    tell_room(environment(caster),(string)caster->query_cap_name()+
      " cures some of "+caster->query_possessive()+" wounds.\n", caster);
  }
  else
  {
    tell_object(target, (string)caster->query_cap_name()+
      " touches you healing several of your wounds.\n");
    tell_object(caster, "You cast Cure Serious Wounds at "+
      (string)target->query_cap_name() + ".\n");
    tell_room(environment(caster),(string)caster->query_cap_name()+
      " casts a spell and cures several of "+target->query_cap_name()+
      "'s wounds.\n", ({target,caster}) );
  }

  switch ( caster->query_sphere_power("healing") )
  {
    case "minor": 
      damage = roll(4,6);
      break;
    case "major": 
      damage = random(20)+2 + random((int)caster->query_level());
      break;
    default:
      damage = roll(6,6);
  }

  damage = cleric_fix_damage(caster,target,damage,save_type);
  target->adjust_hp(damage,caster);

  return 0;
}
