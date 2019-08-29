/*** Major Missile Spell ***/
/*** Created by Eerevann Tokani ***/
/*** Adapted to base spell by Wonderflug ***/

#define TYPE "magical"
#define save_type "magical"

inherit "/std/spells/base.c";

void setup()
{
  set_spell_name("Major Missile");
  set_spell_level(5);
  set_school("invocation");

  set_target_type("one");
  set_range(10);
  set_line_of_sight_needed(0);

  set_help_extras(
    "Damage Type: Magical\n"
    "Saving Throw: None");
  set_help_desc("This spell will send small bolts of energy at the target. "
       " The bolts do 2-5 points of damage each.  The wizard gets 1 missile "
       "for every 2 levels of experience, up to a maximum of 15 missiles.");

  set_gp_cost(10);
  set_casting_time(1);
  set_rounds( ({ "round1" }) );
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int i;
  int damage;
  int NO_OF_DICE;

  NO_OF_DICE = ((caster->query_level())+1)/2;
  NO_OF_DICE = (NO_OF_DICE <= 0 ? 1 : ( NO_OF_DICE > 15 ? 15 : NO_OF_DICE));

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
    return -1;
  }

  if ( !quiet )
  {
    tell_room(environment(caster),(string)caster->query_cap_name()+
      " chants, 'majio magyiz myssl'.\n", ({target,caster}));
    tell_object(caster, "You chant, 'majio magyiz myssl'.\n");
  }
   
  tell_object(target, "You are hit by "+NO_OF_DICE+" magic missile(s).\n");
   
  tell_object(caster, "You cast Major Missile and hit "+
    (string)target->query_cap_name() + " with "+NO_OF_DICE+
    " magic missile(s).\n");
   
  tell_room(environment(caster),(string)caster->query_cap_name()+
    " finishes a spell as "+target->query_cap_name()+" is struck by "+
    NO_OF_DICE+" magic missiles(s).\n",
    ({target,caster}) );

  damage = roll(NO_OF_DICE, 4) + NO_OF_DICE;
  damage = wiz_fix_damage(caster,target,damage,save_type);
  target->spell_damage(target,damage,TYPE,caster);
  target->attack_by(caster);

  return 0;
}
