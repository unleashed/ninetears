/*** Shooting stars Spell ***/
/*** Coded by:  Wonderflug ***/

#define TYPE "magical"
#define SIZE_OF_DICE 6
#define save_type "spells"

#include "weather.h"

inherit "/std/spells/base.c";

void setup()
{
  set_spell_name("Shooting Stars");
  set_spell_level(7);
  set_sphere("astral");

  set_target_type("many");
  set_range(0);

  set_help_extras(
    "Damage Type: " TYPE "\n"
    "Saving Throw: 1/2");
  set_help_desc("This spell envelopes a group of enemies in a hail of shooting "
    "stars. The number of stars brought down is depending on the level of "
    "the caster.  The spell will only work at night and outdoors.");

  set_gp_cost(28);
  set_casting_time(3);
  set_rounds( ({ "round1", "round2", "round3" }) );
}


int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  tell_object(caster, "You raise your hands to the night sky, lost in your "
    "chanting.\n");
  tell_room(environment(caster), caster->query_cap_name()+
    "raises "+caster->query_possessive()+" hands to the night sky, "
    "chanting almost in a fervant trance.\n", caster);

  return 0;
}

int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
  tell_room(environment(caster), "Several stars seem to suddenly move "
    "in the sky.. seemingly falling..\n", ({ }));

  return 0;
}

int round3(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int num_dice, damage;
  int i, j;

   if(!environment(caster)->query_outside()&&!caster->query_static_property("stars_on"))
  {
    tell_object(caster, "This spell can only be cast outdoors.\n");
    return -1;
  }

   if(WEATHER->query_day(environment(caster))&&!caster->query_property("stars_on"))
  {
    tell_object(caster, "There's no stars to bring down during the day.\n");
    return -1;
  }

  if ( !quiet )
  {
    tell_object(caster,"You chant, 'astra nova pyris'.\n");
    tell_room(environment(caster),caster->query_cap_name()+ 
      " chants, 'astra nova manus'.\n", caster);
  }

  if ( !sizeof(target) )
  {
    tell_object(caster, "Alas, there is nobody here by that name.\n");
    return -1;
  }

  num_dice = (int)caster->query_level();

  if(num_dice == 0)
    num_dice = 1;

  tell_object(caster,"You pray to Taniwha and several stars fall "
    "out of the night sky!\n");
  tell_room(environment(caster),caster->query_cap_name()+" prays "
    "fervently and suddenly several stars fall from the heavens, \n"
    "streaking toward the Realms..\n", caster);

  for ( i = 0; i < sizeof(target); i++ )
  {
    if (!living(target[i]) || !target[i]->query_alive()) 
      continue;
    target[i]->attack_by(caster);
    damage = 0;
    damage = roll(num_dice, SIZE_OF_DICE);
    damage = target[i]->spell_saving_throw(target[i],damage,save_type);
    damage = cleric_fix_damage(caster,target[i],damage,TYPE);
    if ( target == caster )
    {
      tell_object(caster, "Oops, a star hits you!  Better be more careful "
        "next time!\n");
      tell_room(environment(caster), caster->query_cap_name()+" screams and "
        "curses as a star hits "+caster->query_objective()+"!\n", caster);
    }
    else switch( damage )
    {
      case 0..10:
        tell_room(environment(caster), target[i]->query_cap_name()+
	  " is slightly burned by a falling star.\n", target[i] );
        tell_object(target[i], "You are slightly burned by a falling star.\n");
        break;
      case 11..30:
        tell_room(environment(caster), "A shooting star hits "+
	  target[i]->query_cap_name()+", burning "+
          target[i]->query_objective()+ " severely.\n", target[i]);
        tell_object(target[i], 
          "A shooting star hits and burns you severely.\n");
        break;
      case 31..80:
        tell_room(environment(caster), target[i]->query_cap_name()+
	  " is incinerated as a falling star nails "+
	  target[i]->query_objective()+".\n", target[i]);
        tell_object(target[i], "You are incinerated by a falling star.\n");
        break;
      case 81..150:
        tell_room(environment(caster), target[i]->query_cap_name()+
	  " is crushed and blasted by a shooting star.\n", target[i]);
        tell_object(target[i], "You are crushed and blasted by a shooting "
	  "star.\n");
        break;
      case 151..10000:
        tell_room(environment(caster), "A shooting star envelops "+
	  target[i]->query_cap_name()+", and "+target[i]->query_pronoun()+
	  " is immolated in a massive \nexplosion of flaming rock.\n",
	  target[i]);
        tell_object(target[i], "A shooting star envelops you, and you are "
	  "immolated in a massive \nexplosion of flaming rock.\n");
        break;
      default:
        tell_room(environment(caster), target[i]->query_cap_name()+
	  " miraculously is unharmed by the falling stars.\n", target[i]);
        tell_object(target[i], "You are unharmed by the shooting stars.\n");
    }
    target[i]->adjust_hp(-damage,caster);
  }

  return 0;
}
