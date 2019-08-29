/*** Cure Light Wounds Spell ***/
/*** Created by Eerevann Tokani ***/
/*** ->base spell by Wonderflug ***/

inherit "/std/spells/base.c";

#define TYPE "magical"
#define save_type "magical"

void setup()
{
  set_spell_name("Cure Light Wounds");
  set_spell_level(1);
  set_sphere("healing");

  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);

  set_help_desc("This spell will cure a small amount of damage "
    "and ease the suffering of any target.  Clerics with more "
    "powerful healing spheres will have more success with this "
    "spell.\n");

  set_gp_cost(2);
  set_casting_time(1);
  set_rounds( ({ "round1" }) );
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet )
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
      " chants, 'magius elis curis'.\n", ({target,caster}));
    tell_object(caster, "You chant, 'magius elis curis'.\n");
  }
    
  if(target == caster)
  { 
    tell_object(target, "You cure some of your minor wounds.\n");
    tell_room(environment(caster),(string)caster->query_cap_name()+
      " cures some of "+caster->query_possessive()+" minor "
      "wounds.\n", caster);
  }
  else
  {
    tell_object(target, (string)caster->query_cap_name()+
      " touches you healing some of your wounds.\n");
    tell_object(caster, "You cast Cure Light Wounds at "+
      (string)target->query_cap_name() + ".\n");
    tell_room(environment(caster),(string)caster->query_cap_name()+
      " casts a spell and cures some of "+target->query_cap_name()+
      "'s wounds.\n",
      ({target,caster}) );
  }

  switch ( caster->query_sphere_power("healing") )
  {
    case "minor" :  
      damage = random(8) + 1;
      break;
    case "neutral": 
      damage = random(14) + 2;
      break;
    case "major": 
      damage = random((int)caster->query_level()) + 1;
      break;
    default:  
      damage = random(8)+1;
  }

  damage = cleric_fix_damage(caster,target,damage,save_type);
  target->adjust_hp(damage,caster);

  return 0;
}
