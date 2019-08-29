/*** Cure Critical Wounds Spell ***/
/*** Created by Eerevann Tokani ***/
/*** ->base spell by Wonderflug ***/

inherit "/std/spells/base.c";

#define TYPE "magical"
#define save_type "magical"

void setup()
{
  set_spell_name("Cure Critical Wounds");
  set_spell_level(15);
  set_sphere("healing");

  set_target_type("many");
  set_range(0);
  set_line_of_sight_needed(0);

  set_help_desc("This spell has been known to work miracles, healing the "
    "gravest wounds up to perfect health.  It is said to be somewhat "
    "stunning to the caster, for worshippers of deities with lesser powers "
    "of healing. Note that this spell cures multiple targets.\n");

  set_gp_cost(10);
  set_casting_time(1);
  set_rounds( ({ "round1" }) );
}

int round1(object caster, mixed targets, mixed out_range, int time, int quiet)
{
  int damage,i;
  object target;

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

  switch( caster->query_spell_power("healing") )
  {
    case "minor":  
      damage = roll((int)caster->query_level(), 3);
      caster->add_timed_property("stillcasting", 1, 2);
      break;
    case "major": 
      damage = 20 + roll((int)caster->query_level(), 5);
      break;
    default:
      damage = roll((int)caster->query_level(), 4);
      caster->add_timed_property("stillcasting", 1, 1);
  }
   
  tell_room(environment(caster),(string)caster->query_cap_name()+
      " casts a spell and cures many grevious wounds.\n",
      ({target,caster}) );
  for(i = 0; i < sizeof(targets); i++)
  {
  	target = targets[i];	    
  	if(target == caster)
  	{
    		tell_object(target, "You cure some of your grevious wounds.\n");
  	}
  	else
  	{
    		tell_object(target, (string)caster->query_cap_name()+
      		" touches you healing many of your grevious wounds.\n");
  	}
  	damage = cleric_fix_damage(caster,target,damage,save_type);
  	target->adjust_hp(damage,caster);
  }
  return 0;
}
