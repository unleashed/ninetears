/*** Sticks to Snakes -- Druids Spell ***/
/*** By Wonderflug ***/

#include "tweaks.h"

inherit "/std/spells/patch.c";

mixed find_one_match(string find,mixed in);
int cleric_fix_damage(object caster,object victim,int damage,string save);

#define SP_NAME "Sticks to Snakes"
#define GP_COST STICK_GP
#define SPELLTYPE "offensive"

string help() 
{
  return
       "\n\n"
       "Spell Name: "+SP_NAME+"\n"
       "Sphere: Druids\n"
       "Level: 2nd\n"
       "Gp Cost: "+GP_COST+"\n"
	"Saving Throw: None\n\n"
        "Description: \n"
	"     This spell will turn all sticks in the Druid's inventory "
	"into snakes.  The maximum number of sticks that can be transformed "
	"is one per 3 levels of the druid.  The snakes will defend the "
	"Druid until all attackers have either fled or been killed, or "
	"the Druid herself is killed or leaves.  Once any of these "
	"conditions have been met, the snakes "
	"will return to their natural homes, living out the normal life of a "
	"snake.  The sticks cannot be recovered.\n\n";
}

mixed spell( string str, object caster );

int cast_spell(string str,object cast)
{
  int skill;
  mixed ret;
  object caster;

  caster = cast ? cast : this_player();

  if(interactive(caster))
	  str = (string)caster->expand_nickname(str);

  ret = spell(str, caster);
  if (stringp(ret))
  {
    notify_fail(ret);
	 return 0;
  }

  tell_object(caster,"You start to cast "+SP_NAME+".\n");
  tell_room(environment(caster),caster->query_cap_name()+" begins to cast "
	"a spell.\n",
	caster);
  return 1;
}

mixed spell(string str, object caster)
{
  mixed ob;

  if ((int)caster->query_spell_effect(SPELLTYPE))
    return "You are already casting an "+SPELLTYPE+" spell.\n";

  ob = find_unique_match(STICKNAME, caster);
  if (!sizeof(ob))
    return "You don't have any sticks.\n";

  caster->add_spell_effect(3, SPELLTYPE, SP_NAME,
    this_object(), "hb_spell", ({ ob }));
  return 1;
}

int hb_spell(object caster, mixed *params, int time)
{
  int i, j;
  object snake;

  switch( time )
  {
    case 3:
	tell_object(caster, "You draw in power from the world for your "
	  "enchantment.\n");
	tell_room(environment(caster), caster->query_cap_name()+" goes into "
	  "an odd trance-like state.\n", caster);
	return 0;
    case 2:
	tell_object(caster, "You throw several sticks down on the ground.\n");
	tell_room(environment(caster),caster->query_cap_name()+
	  " throws several sticks down on the ground.\n", caster );
	for ( i=0;i<sizeof(params[0]);i++)
	  caster->drop_ob(params[0]->query_name());
	return 0;
    default:
	break;
  }
  if ((int)caster->adjust_gp(-GP_COST)<0)
  {
	tell_object(caster, "You don't have enough power to transform the "
	  "sticks to snakes.\n");
	tell_room(environment(caster), caster->query_cap_name()+" sways "
	  "tiredly and stares defeatedly at the sticks.\n", caster);
    	return 0;
  }

  tell_object(caster, "You transform the sticks into small but vicious "
	"snakes.\n\nThe snakes start attacking your enemies.\n");
  tell_room(environment(caster), "The sticks suddenly morph into snakes "
	"and protect "+caster->query_cap_name()+"!\n", caster);

  i = (int)caster->query_level() / 3;
  if ( i > sizeof(params[0]) )
	i = sizeof(params[0]);

  for (j=0; j < i; j++)
  {
	snake = clone_object(SNAKE);
	snake->set_spell(caster);
	params[0][j]->dest_me();
  }

  return GP_COST*i;
}
