/*** Fire Burst Spell ***/
/*** Coded by:  Eerevann Tokani ***/
/*** Adapted to base spell by Wonderflug, why do I bother? ***/

#define TYPE "fire"
#define save_type "fire"

inherit "/std/spells/base.c";

void setup()
{
  set_spell_name("Fire Burst");
  set_spell_level(1);
  set_school("invocation");

  set_target_type("many");
  set_range(0);
  set_line_of_sight_needed(0);

  set_help_extras(
    "Damage Type: " TYPE "\n"
    "Saving Throw: 1/2");
  set_help_desc("This spell creates a small burst of flames that envelopes your"
    " enemies for 1 point for each of your levels.  Maximum damage is 10.");

  set_gp_cost(2);
  set_casting_time(1);
  set_rounds( ({ "round1" }) );
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int damage;
  string str;
  int NO_OF_DICE;
  int j;
  int i;
 
  damage = (int)caster->query_level();
  if (damage > 10)
    damage = 10;
  
  if((i = member_array(caster, target)) != -1)
    target = delete(target, i, 1);
  
  if(!sizeof(target)) 
  {
    tell_object(caster, "There is noone here by that name.\n");
    return -1;
  }

  if ( !quiet )
  {
    tell_room(environment(caster), caster->query_cap_name()+
      " chants, 'pyros burios'.\n", ({caster,target}));
    tell_object(caster, "You chant, 'pyros burios'.\n");
  }
  
  i = 0;

  for ( i=sizeof(target)-1; i>=0; i-- )
  {
    target[i]->attack_by(caster);
    target[i]->spell_damage(target[i],
      wiz_fix_damage(caster, target[i],damage,save_type), TYPE,caster);
    tell_object(target[i], caster->query_cap_name() +" hits you with a "
      "small burst of flame!\n");
    if ( !target[i] )
      target = delete(target, i, 1);
  }

  tell_room(environment(caster), caster->query_cap_name() + " envelopes "+
    (str = query_multiple_short(target))+
    " with a small burst of flame!\n", ({caster,target}));
  tell_object(caster, "You envelope " + str + " in a Fire Burst!\n");

  return 0;
}
