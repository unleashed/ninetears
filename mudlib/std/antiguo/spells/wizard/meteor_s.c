/*** Meteor Swarm Spell ***/
/*** Coded by:  Eerevann Tokani ***/
/*** Adapted to base spell by Wonderflug ***/

#define SP_NAME "Meteor Swarm"
#define GP_COST 18
#define TYPE "missile"
#define SIZE_OF_DICE 4
#define save_type "stone"

inherit "/std/spells/base.c";

void setup()
{
  set_spell_name("Meteor Swarm");
  set_spell_level(9);
  set_school("invocation");

  set_target_type("many");
  set_range(2);
  set_line_of_sight_needed(1);

  set_help_extras(
    "Damage Type: " TYPE "\n"
    "Saving Throw: 1/2");
  set_help_desc("This spell will envelope your enemies in a fiery shower of "
    "meteors which explode upon impact, hitting every target in the blast "
    "radius (ie, range).  The damage is 40-160 points damage.");

  set_casting_time(2);
  set_gp_cost(18);
  set_rounds(
    ({
      ({
        "4 flaming spheres of molten rock appear in the air before you.\n",
        "4 flaming balls of molten rock suddenly appear in the air.\n"
      }),
      "round2"
    }) );

}


int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int damage;
  string str;
  int NO_OF_DICE;
  int j;
  int i;
 
  NO_OF_DICE = 40;

  
  if((i = member_array(caster, target)) != -1)
    target = delete(target, i, 1);
  

  if ( !quiet )
  {
    tell_room(environment(caster), caster->query_cap_name()+
      " chants, 'meseious pyros blasious'.\n", caster);
    tell_object(caster, "You chant, 'meseious pyros blasious'.\n");
  }

  if(!sizeof(target)) 
  {
    tell_object(caster, "Blasts of molten rock reign down around.. "
      "nobody.  Everyone got away.\n");
    tell_room(environment(caster), caster->query_cap_name()+" gestures "
      "and meteors fall in a massive rain of harmlessness, hitting nobody.\n",
      caster);
    return -1;
  }
  
  tell_object(caster, "You send the swarm of meteors into a rain of "
    "death and destruction.\n");
  tell_room(environment(caster), caster->query_cap_name()+" gestures and "
    "meteors fall in a rain of death and destruction.\n", caster);

  i = 0;
  for ( i=sizeof(target)-1; i>=0; i-- )
  {
    tell_object(target[i], "A meteor rains down out of the sky and "
      "blasts into you!\n");
    tell_room(environment(target[i]), target[i]->query_cap_name()+
      " disappears in the explosion of a falling meteor!\n",
      target[i]);
    target[i]->attack_by(caster);
    damage = 0;
    damage = roll(NO_OF_DICE, SIZE_OF_DICE);
    damage = wiz_fix_damage(caster,target[i],damage,save_type);

    if ( (int)target[i]->query_hp() < damage )
      tell_object(caster, target[i]->query_cap_name()+" is obliterated "
        "into a pile of ash by your spell!\n");

    target[i]->spell_damage(target[i],damage,TYPE,caster);

    if ( !target[i] )
      target = delete(target, i, 1);
  }

  tell_object(caster, "You envelop "+query_multiple_short(target)+
    " in the meteor shower.\n");

  if ( sizeof(out_range) )
    tell_object(caster, "Alas, "+query_multiple_short(out_range)+
      " fled to safety.\n");

  return 0;

}
