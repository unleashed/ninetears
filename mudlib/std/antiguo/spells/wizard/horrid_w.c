/*** Yes, rewrote again, by Wonderflug ***/

#include "tweaks.h"
#define TYPE "air"
#define SIZE_OF_DICE 8
#define save_type "air"

inherit "/std/spells/base.c";

void setup()
{
  set_spell_name("Horrid Wilting");
  set_spell_level(8);
  set_school("necromancy");

  set_target_type("many");
  set_range(0);
  set_line_of_sight_needed(0);

  set_help_extras(
    "Damage Type: " TYPE "\n"
    "Saving Throw: 1/2");
  set_help_desc("This spell will evaporate all the moisture from the bodies "
    "of your enemies.  The damage is equal to the casters level times "
    "8.  A 16th level Wizard could do 16-128 points of damage.  There is "
    "no limit to the damage done by this spell.");

  set_gp_cost(16);
  set_casting_time(2);
  set_rounds( 
    ({ 
      ({
        "You chant very softly, and the air suddenly tingles with unleashed "
          "power.\n",
        "Suddenly the air seems to tingle against your skin, as if some "
          "massive power is about to be unleashed.\n",
      }),
      "round2" 
    }) );
}

int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int damage;
  int NO_OF_DICE;
  int i;
 
  if ( !target || !sizeof(target) )
  {
    tell_object(caster, 
      "Your spell failed ... there is nobody of that name here.\n");
    return -1;
  }

  if ( !quiet )
  {
    tell_object(caster, "Your chanting becomes a shout: 'wilos magius "
      "evapious'!\n");
    tell_room(environment(caster), caster->query_cap_name()+" shouts "
      "dreadfully, 'wilos magius evapious'!\n", caster);
  }

  if ( (i = member_array(caster, target)) != -1)
    target = delete(target, i, 1);
  
  if(!sizeof(target)) 
  {
    tell_object(caster, "There is noone here by that name.\n");
    return -1;
  }

  caster->add_timed_property("stillcasting",1,3);

  NO_OF_DICE = caster->query_level();
  if(NO_OF_DICE == 0)
    NO_OF_DICE = 1;

  i = 0;
  for ( i=sizeof(target)-1; i>=0; i-- )
  {
    tell_object(target[i], caster->query_cap_name()+" finishes a spell "
      "as you can feel the moisture from you body evaporating!\n");
    tell_object(caster, "You vaporise "+target[i]->query_cap_name()+"!\n");
    tell_room(environment(caster), caster->query_cap_name()+
      " vaporises "+target[i]->query_cap_name()+".\n",
      ({ caster, target[i] }) );

    damage = 0;
    target[i]->attack_by(caster);
    damage = roll(NO_OF_DICE, SIZE_OF_DICE);
    damage = wiz_fix_damage(caster,target[i],damage,save_type);
    target[i]->spell_damage(target[i],damage,TYPE,caster);
    if(!target[i])
      target = delete(target, i, 1);
  }

  if ( sizeof(out_range) )
    tell_object(caster, "Alas, "+query_multiple_short(out_range)+
      " managed to get out of range.\n");

  return 0;
}

