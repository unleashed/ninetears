/*** Ice Storm Spell ***/
/*** Coded by:  Eerevann Tokani ***/
/* Modified for NPC's and wands Taniwha */
/* Adapted to base spell Wonderflug 96 */


#define TYPE "cold"
#define SIZE_OF_DICE 10
#define save_type "cold"

inherit "/std/spells/base.c";

void setup()
{
  set_spell_name("Ice Storm");
  set_spell_level(5);
  set_school("invocation");

  set_target_type("many");
  set_range(0);
  set_line_of_sight_needed(0);

  set_help_extras(
    "Damage Type: " TYPE "\n"
    "Saving Throw: None");
  set_help_desc("This spell will pelt everyone in the area in a "
    " storm of icy shards and hail.  The damage is 3-30 points of damage.");

  set_gp_cost(10);
  set_casting_time(1);
  set_rounds( ({ "round1" }) );
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int damage;
  int i;
  string str;
 
  /* to remove the caster, if he uses 'all' */
  if((i = member_array(caster, target)) != -1)
    target = delete(target, i, 1);
  
  if(!sizeof(target)) 
  {
    tell_object(caster, "There is noone here by that name.\n");
    return -1;
  }

  if ( !quiet )
  {
    tell_room(environment(caster), caster->query_cap_name()
      + " chants, 'sormus frez os halos'.\n", ({caster,target}));
    tell_object(caster, "You chant, 'sormus frez os halos'.\n");
  }
  
  for ( i=sizeof(target)-1; i>=0; i-- )
  {
    target[i]->attack_by(caster);
    damage = roll(3, SIZE_OF_DICE);
    damage = wiz_fix_damage(caster,target[i],damage,save_type);
    target[i]->spell_damage(target[i],damage,TYPE,caster);
    tell_object(target[i], caster->query_cap_name()+ 
      " conjures an ice storm and pelts you with icy shards!\n");

    if(!target[i])
      target = delete(target, i, 1);
  }

  tell_room(environment(caster), caster->query_cap_name() + 
    " envelopes "+(str = query_multiple_short(target))+
    " within an icy storm!\n", ({caster,target}));
  tell_object(caster, "You envelope " + str + " in a Ice Storm!\n");

  return 0;
}
