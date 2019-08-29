/*** Magic Missile Spell ***/
/*** Created by Eerevann Tokani ***/
/* fixed Taniwha '95 NPC and wands */
/*** Adapted to base spell, Wonderflug 96 ***/

inherit "/std/spells/base.c";

#define TYPE "magical"
#define SIZE_OF_DICE 4
#define save_type "magical"

void setup()
{
  set_spell_name("Magic Missile");
  set_school("invocation");
  set_spell_level(1);

  set_target_type("one");
  set_range(10);
  set_line_of_sight_needed(0);

  set_help_extras(
    "Damage Type: Magical\n"
    "Saving Throw: None");
  set_help_desc("This spell will send small bolts of energy at the target. The"
    " bolts do 2-5 points of damage each.  The wizard gets 1 missile "
    "for every 2 levels of experience, up to a maximum of 5 missiles.");

  set_gp_cost(2);
  set_casting_time(1);
  set_rounds( ({ "round1" }) );
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int i;
  int damage;
  int NO_OF_DICE;

  NO_OF_DICE = ((caster->query_level())+1)/2;
  NO_OF_DICE = (NO_OF_DICE <= 0 ? 1 : (NO_OF_DICE > 5 ? 5 : NO_OF_DICE ));

  if (!target)
  {
    tell_object(caster,
      "Your spell failed ... there is no one of that name here.\n");
    return -1;
  }

  if(target == caster)
  { 
    tell_object(target, "Wouldn't that be suicide?\n");
    tell_room(environment(caster),(string)caster->query_cap_name()+
      " stops casting.\n",target);
  }

  if ( !quiet )
  {
    tell_room(environment(caster),(string)caster->query_cap_name()+
      " chants, 'magyiz myssl'.\n", ({target,caster}));
    tell_object(caster, "You chant, 'magyiz myssl'.\n");
  }
    
  tell_object(target, "You are hit by "+NO_OF_DICE+" magic missile(s).\n");
  tell_object(caster, "You cast Magic Missile and hit "+
    (string)target->query_cap_name() + " with "+NO_OF_DICE+
    " magic missile(s).\n");
   
  if ( environment(caster) == environment(target) )
    tell_room(environment(caster),(string)caster->query_cap_name()+
      " gestures as "+target->query_cap_name()+" is struck by "+
      NO_OF_DICE+" magic missiles(s).\n",
      ({target,caster}) );
  else
  {
    tell_room(environment(caster), caster->query_cap_name()+" gestures and "
      +NO_OF_DICE+" missiles go flying off somewhere.\n", caster);
    tell_room(environment(target), target->query_cap_name()+" is hit by "
      +NO_OF_DICE+" glowing missiles that flew in from somewhere.\n", target);
  }

  damage = roll(NO_OF_DICE, SIZE_OF_DICE)+NO_OF_DICE;
  damage = wiz_fix_damage(caster,target,damage,save_type);
  target->spell_damage(target,damage,TYPE,caster);
  target->attack_by(caster);

  return 0;
}
