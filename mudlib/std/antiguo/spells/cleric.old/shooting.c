/*** Fireball Spell ***/
/*** Coded by:  Wonderflug ***/

#define SP_NAME "Shooting Stars"
#define GP_COST 14
#define TYPE "magical"
#define SIZE_OF_DICE 6
#define save_type "spells"

#include "weather.h"
inherit "/std/spells/patch.c";

/* find_unique_match() does a find match that ensures the returned 
   object list contains no duplicates
   find_one_match() returns only the first matched object
*/
mixed find_unique_match(string find,mixed in);
mixed find_one_match(string find,mixed in);

string help() {
       return
       "\n\n"
       "Spell Name: "+SP_NAME+"\n"
       "Sphere: Astral\n"
       "Level: 7th\n"
       "Gp Cost: "+GP_COST+"\n"
       "Damage Type: "+TYPE+"\n"
       "Saving Throw: 1/2\n"
       "Description: \n"
       "     This spell envelopes a group of enemies in a hail of shooting "
       "stars. The number of stars brought down is depending on the level of "
       "the caster.  The spell will only work at night and outdoors.\n"
       "\n";

}


int cast_spell(string str,object who)
{
  int skill;
  mixed ret;
  object caster;

  caster = who ? who : this_player();

  if ( caster->query_property("cast") )
  {
	tell_object(caster, "You are already casting a spell.\n");
	return 1;
  }
  if ( ! ( (environment(caster))->query_outside() ) )
  {
	tell_object(caster, "This spell can only be cast outdoors.\n");
	return 1;
  }
/*  Take this out for now;  shouldn't be able to cast during the day but
   * seems like day/night doesn't work -- Actually it does so putting in */
  if ( WEATHER->query_day(environment(caster)) )
  {
	tell_object(caster, "There's no stars to bring down during the day.\n");
	return 1;
  }
  if ( (int)caster->query_gp() < GP_COST )
  {
	tell_object(caster,"You feel too drained to cast.\n");
	return 1;
  }

  tell_object(caster,"You begin to cast "+SP_NAME+".\n");
  tell_room(environment(caster),caster->query_cap_name()+" begins casting "
	"a spell.\n",
	caster);

  caster->adjust_gp(-GP_COST);
  caster->add_timed_property("cast",1,2);
  call_out("make_spell",2,caster,str);
  tell_object(caster,"You chant, 'astra nova pyris'.\n");
  tell_room(environment(caster),caster->query_cap_name()+ 
	" chants, 'astra nova manus'.\n", caster);
  return 1;
}

void make_spell( object caster, string str )
{
  object* ob;
  int num_dice, damage;
  int i, j;

  if (!str)
  {
	tell_object(caster, "Your target isn't here.\n");
	return;
  }

  ob = find_unique_match(str, environment(caster));

  if (!sizeof(ob))
  {
	tell_object(caster, "Your target isn't here.\n");
	return;
  }

  num_dice = (int)caster->query_level();

  if(num_dice == 0)
	num_dice = 1;

  tell_object(caster,"You pray to Lathander and several stars fall "
	"out of the night sky!\n");
  tell_room(environment(caster),caster->query_cap_name()+" prays "
	"fervently and suddenly several stars fall from the heavens, \n"
	"streaking toward the Realms..\n", caster);

  i = 0;
  while(i<sizeof(ob)) 
  {
	if (!living(ob[i])) 
		continue;
	ob[i]->attack_by(caster);
	damage = 0;
	for ( j=1; j<=num_dice; j++)
		damage = damage + random(SIZE_OF_DICE);
	damage = ob[i]->spell_saving_throw(ob[i],damage,save_type);
	damage = cleric_fix_damage(caster,ob[i],damage,TYPE);
	ob[i]->adjust_hp(-damage,caster);
	switch( damage )
	{
	  case 0..10:
	    tell_room(environment(caster), ob[i]->query_cap_name()+
		" is slightly burned by a falling star.\n", ob[i] );
	    tell_object(ob[i], "You are slightly burned by a falling star.\n");
	    break;
	  case 11..30:
	    tell_room(environment(caster), "A shooting star hits "+
		ob[i]->query_cap_name()+", burning "+ob[i]->query_objective()+
		" severely.\n", ob[i]);
	    tell_object(ob[i], "A shooting star hits and burns you severely.\n");
	    break;
	  case 31..80:
	    tell_room(environment(caster), ob[i]->query_cap_name()+
		" is incinerated as a falling star nails "+
		ob[i]->query_objective()+".\n", ob[i]);
	    tell_object(ob[i], "You are incinerated by a falling star.\n");
	    break;
	  case 81..150:
	    tell_room(environment(caster), ob[i]->query_cap_name()+
		" is crushed and blasted by a shooting star.\n", ob[i]);
	    tell_object(ob[i], "You are crushed and blasted by a shooting "
		"star.\n");
	    break;
	  case 151..10000:
	    tell_room(environment(caster), "A shooting star envelops "+
		ob[i]->query_cap_name()+", and "+ob[i]->query_pronoun()+
		" is immolated in a massive \nexplosion of flaming rock.\n",
		ob[i]);
	    tell_object(ob[i], "A shooting star envelops you, and you are "
		"immolated in a massive \nexplosion of flaming rock.\n");
	    break;
	  default:
	    tell_room(environment(caster), ob[i]->query_cap_name()+
		" miraculously is unharmed by the falling stars.\n", ob[i]);
	    tell_object(ob[i], "You are unharmed by the shooting stars.\n");
	}
	i++;
  }


  return GP_COST;

}
