/*** Lightning Bolt Spell ***/
/*** Created by Eerevann Tokani ***/
/*** Adapted to base spell by Wonderflug ***/

#define TYPE "electrical"
#define SIZE_OF_DICE 6
#define save_type "electrical"

inherit "/std/spells/base.c";

void setup() 
{
  set_spell_name("Lightning Bolt");
  set_spell_level(3);
  set_school("invocation");

  set_target_type("one");
  set_range(4);
  set_line_of_sight_needed(0);

  set_help_extras(
    "Damage Type: " TYPE "\n"
    "Saving Throw: 1/2" );
  set_help_desc("This spell will strike a single target with a bolt of "
    "lightning.  The damage done is (caster's level)d6.  Maximum "
    "damage is 10d6.\n");

  set_gp_cost(6);
  set_casting_time(1);
  set_rounds( ({ "round1" }) );
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
 
  int i;
  int damage;
  int NO_OF_DICE;

  NO_OF_DICE = caster->query_level();
  NO_OF_DICE = ( NO_OF_DICE <= 0 ? 1 : ( NO_OF_DICE > 10 ? 10 : NO_OF_DICE ));

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
      " chants, 'xlxyx de gadrum'.\n", ({caster}));
    tell_object(caster, "You chant, 'xlxyx de gadrum'.\n");
  }
    
  tell_object(target, (string)caster->query_cap_name()+
    " fries you with a Lightning Bolt.\n");
   
  tell_object(caster, "You fry "+(string)target->query_cap_name()+
    " with a Lightning Bolt.\n");

  tell_room(environment(caster),(string)caster->query_cap_name()+
    " finishes a spell and "+target->query_cap_name()+" is struck "
    "with a lightning bolt.\n", ({target,caster}) );

  damage = roll(NO_OF_DICE, SIZE_OF_DICE);
  damage = wiz_fix_damage(caster,target,damage,save_type);
  target->spell_damage(target,damage,TYPE,caster);
  target->attack_by(caster);

  return 0;

}
