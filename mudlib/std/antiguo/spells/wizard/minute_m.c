/*** Minute Meteors Spell ***/
/*** Created by Eerevann Tokani ***/
/*** Adapted to base spell by wonderflug ***/

inherit "/std/spells/base.c";

#define TYPE "missile"
#define SIZE_OF_DICE 4
#define save_type "magical"


void setup()
{
  set_spell_name("Minute Meteors");
  set_spell_level(3);
  set_school("invocation");

  set_target_type("one");
  set_range(3);
  set_line_of_sight_needed(1);

  set_help_extras(
    "Damage Type: " TYPE "\n"
    "Saving Throw: None");
  set_help_desc("This spell creates small globes of fire which are hurled at "
    "a single target.  Each globe does 1d4 points of damage.  The "
    "caster creates 1 globe for each level of experience with a "
    "maximum of 10 globes being created.\n");

  set_gp_cost(6);
  set_casting_time(1);
  set_rounds( ({ "round1" }) );
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
 
  int damage;
  int NO_OF_DICE;
  int i;

  NO_OF_DICE = caster->query_level();
  NO_OF_DICE = (NO_OF_DICE <= 0 ? 1 : ( NO_OF_DICE > 10 ? 10 : NO_OF_DICE ));

  if ( !target )
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
    tell_object(caster, "You chant, 'miute pyros sphyes'.\n");
    tell_room(environment(caster),(string)caster->query_cap_name()+
      " chants, 'miute pyros sphyes'.\n", ({target,caster}));
  }
    
   
  tell_object(target, (string)caster->query_cap_name()+
    " hits you with "+NO_OF_DICE+" globes of flame.\n");
   
  tell_object(caster, "You hit "+(string)target->query_cap_name()+ 
    " with "+NO_OF_DICE+" globes of flame.\n");
   
  tell_room(environment(caster), target->query_cap_name()+" is hit with "+
    NO_OF_DICE+" globes of flame.\n", ({target,caster}) );

  damage = roll(NO_OF_DICE, SIZE_OF_DICE);
  damage = wiz_fix_damage(caster,target,damage,save_type);
  target->spell_damage(target,damage,TYPE,caster);

  target->attack_by(caster);

  return 0;
}
