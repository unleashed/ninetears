/*** Cure Critical Wounds Spell ***/
/*** Created by Eerevann Tokani ***/
/*** ->base spell by Wonderflug ***/

inherit "/std/spells/base.c";

#define TYPE "magical"
#define save_type "magical"

void setup()
{
  set_spell_name("Cure Critical Wounds");
  set_spell_level(5);
  set_sphere("healing");

  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);

  set_help_desc("This spell has been known to work miracles, healing the "
    "gravest wounds up to perfect health.  It is said to be somewhat "
    "stunning to the caster, for worshippers of deities with lesser powers "
    "of healing.\n");

  set_gp_cost(10);
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
      " chants, 'magius criusis curis'.\n", ({target,caster}));
    tell_object(caster, "You chant, 'magius criusis curis'.\n");
  }
    
  if(target == caster)
  {
    tell_object(target, "You cure some of your grevious wounds.\n");
    tell_room(environment(caster),(string)caster->query_cap_name()+
      " cures some of "+caster->query_possessive()+" grevious"
      " wounds.\n", caster);
  }
  else
  {
    tell_object(target, (string)caster->query_cap_name()+
      " touches you healing many of your grevious wounds.\n");
    tell_object(caster, "You cast Cure Critical Wounds at "+
      (string)target->query_cap_name() + ".\n");
   
    tell_room(environment(caster),(string)caster->query_cap_name()+
      " casts a spell and cures many of "+target->query_cap_name()+
      "'s grevious wounds.\n",
      ({target,caster}) );
  }

  switch( caster->query_spell_power("healing") )
  {
    case "minor":  
      damage = roll((int)caster->query_level(), 3);
      caster->add_timed_property("stillcasting", 1, 2);
      break;
    case "major": 
      damage = roll((int)caster->query_level(), 5);
      break;
    default:
      damage = roll((int)caster->query_level(), 4);
      caster->add_timed_property("stillcasting", 1, 1);
  }

  damage = cleric_fix_damage(caster,target,damage,save_type);

  target->adjust_hp(damage,caster);

  return 0;
}
