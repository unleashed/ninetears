/* Quake */
/* Version without UD_query.c, for use by NPCs only */

 
#define TYPE "magical"
#define SIZE_OF_DICE 3
#define save_type "stone"

#include "weather.h"

inherit "/std/spells/base.c";

void setup()
{
	set_spell_name("Earthquake");
  set_spell_level(7);
	set_sphere("combat");

  set_target_type("many");
  set_range(0);

  set_help_extras(
    "Damage Type: " TYPE "\n"
    "Saving Throw: 1/2");
	set_help_desc("This spell causes the earth to quake, so that"
		" a group of your enemies suffers the force of"
		" Cyrcia's wrath.  This spell will only work"
		" in the Underdark.  Be warned; the destructive nature"
		" of this spell is such that the caster shall lose"
		" knowledge of the spell 'heal'.  Equally important,"
		" should the spell's target leave, then Cyrcia will"
		" demand payment from the caster...\n");

   set_gp_cost(15);
  set_casting_time(3);
  set_rounds( ({ "round1", "round2", "round3" }) );
}


int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
tell_object(caster, "You raise your hands to the rocky ceiling.\n");
  tell_room(environment(caster), caster->query_cap_name()+
	" raises "+caster->query_possessive()+" hands to the rocky"
	" ceiling, chanting in a low hiss.\n", caster);

  return 0;
}

int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
tell_room(environment(caster), "The earth begins to tremble,"
	" shuddering in warning..\n", ({ }));

  return 0;
}

int round3(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int num_dice, damage;
	int cleric_level;
  int i, j;

  if ( !quiet )
  {
	tell_object(caster,"You chant, 'terra firma venit'.\n");
    tell_room(environment(caster),caster->query_cap_name()+ 
	" chants, 'terra firma venit'.\n", caster);
  }
num_dice = (12 + random(5) + random(caster->query_level()/5) +
	random(caster->query_level()));

  if ( !sizeof(target) )
  {
  tell_object(caster, "The energies coursing through you can not"
		" find the specified target.  Desperately, you"
		" try to stop the spell, but the magic expands"
		" with a life of its own, turning upon you in"
		" anger!\n\n");
  tell_room(environment(caster), caster->query_cap_name()+
		" is suddenly overcome with fear, as the magic"
		" overcomes "+caster->query_possessive()+
		" mental barriers.  Flames leap in"
		" "+caster->query_possessive()+" eyes, and"
		" "+caster->query_pronoun()+" screams, ravaged"
		" from within!\n", caster);
  damage = 0;
  damage = roll(num_dice, SIZE_OF_DICE);
  damage = caster->spell_saving_throw(caster, damage, save_type);
  damage = cleric_fix_damage(caster, caster, damage, TYPE);
  caster->adjust_hp(-damage, caster);
    return -1;
  }



	tell_object(caster,"You pray to Cyrcia and the earth "
	"splits beneath the feet of your enemies!\n");
  tell_room(environment(caster),caster->query_cap_name()+" prays "
	"fervently and the earth shakes wildly, splitting"
	" open!\n", caster);

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
	tell_object(caster, "You fool!  You bring the wrath of"
		" Cyrcia upon yourself??\n");
      tell_room(environment(caster), caster->query_cap_name()+" screams and "
	"curses as the earth collapses"
	" beneath "+caster->query_objective()+"!\n", caster);
    }
	else switch( damage )
    {
      case 0..10:
        tell_room(environment(caster), target[i]->query_cap_name()+
	" is rocked back by the force of the quake.\n", target[i] );
	tell_object(target[i], "You are rocked back by an earthquake.\n");
        break;
      case 11..30:
	tell_room(environment(caster), target[i]->query_cap_name()+
	" is knocked off "+target[i]->query_possessive()+" feet"
	" by an earthquake.\n", target[i]);
        tell_object(target[i], 
	"The force of the earthquake knocks you off your feet.\n");
        break;
      case 31..80:
        tell_room(environment(caster), target[i]->query_cap_name()+
	" is knocked violently against the wall by the"
	" earthquake!\n", target[i]);
	tell_object(target[i], "You are slammed violently against the"
		" wall by the earthquake.\n");
        break;
	case 81..120:
	tell_room(environment(caster), "The earth opens up and "+
	"swallows "+target[i]->query_cap_name()+" whole.\n",
	target[i]);
	tell_object(target[i], "The earth opens and swallows you"
	" whole, flooding your senses with pain.\n");
        break;
	case 121..10000:
	tell_room(environment(caster), "The earth splits wide"
	" beneath "+target[i]->query_cap_name()+" and from the"
		" chasm comes a flare of magma, scorching"+
	" "+target[i]->query_objective()+" with its heat.\n", target[i]);
	tell_object(target[i], "As the earth gives way beneath you,"
		" a blast of superheated air, and molten magma"
		" spews up to char your tortured frame.\n");
        break;
      default:
        tell_room(environment(caster), target[i]->query_cap_name()+
	" miraculously is unharmed by the earthquake.\n", target[i]);
	tell_object(target[i], "You are unharmed by the earthquake.\n");
    }
    target[i]->adjust_hp(-damage,caster);
    caster->remove_spell("heal");
  }

  return 0;
}
