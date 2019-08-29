/*** Magical Vestment Spell ***/
inherit "/std/spells/patch.c";

/* find_unique_match() does a find match that ensures the returned 
   object list contains no duplicates
   find_one_match() returns only the first matched object
*/
mixed find_unique_match(string find,mixed inx);
mixed find_one_match(string find,mixed inx);
int cleric_fix_damage(object caster,object victim,int damage,string save);
object caster;
/*** Created by Eerevann Tokani ***/


#define SP_NAME "Magical Vestment"
#define GP_COST 6
#define SPELLTYPE "defensive"


string help() {
		 return
       "\n\n"
		 "Spell Name: "+SP_NAME+"\n"
       "Sphere: Protection\n"
       "Level: 3rd\n"
       "Gp Cost: "+GP_COST+"\n"
		 "Description: \n"
		 "    This spell creates a suit of magical armour for the caster "
       "to wear.  The armour is equal to Chainmail, AC 5.  The vestment " 
       "receives a -1 enchantment for every 3 levels of the caster beyond "
       "5th, to a maximum of AC 1 at 17th level.  The vestment lasts for "
       "moderate amount of time dependant upon the casters level.\n\n";
       

}

mixed spell(string str, int skill, int cast);

int cast_spell(string str,object cast)
{
  int skill;
  mixed ret;

  caster = cast ? cast : this_player();

  if(interactive(caster))
	  str = (string)caster->expand_nickname(str);

  ret = spell(str, skill, 1);
  if (stringp(ret))
  {
    notify_fail(ret);
	 return 0;
  }
  tell_object(caster,"You start to cast "+SP_NAME+".\n");
  tell_room(environment(caster),caster->query_cap_name()+" begins to cast a spell.\n",
	  caster);
  return 1;
  }

mixed spell(string str, int skill, int cast)
{
  mixed ob;

  if ((int)caster->query_spell_effect(SPELLTYPE))
	 return "You are already casting a "+SPELLTYPE+" spell.\n";
  ob = find_one_match(str, environment(caster));
  if (sizeof(ob))
    ob = ob[0];
  else
    ob = 0;

  caster->add_spell_effect(1, SPELLTYPE, SP_NAME,
    this_object(), "hb_spell", ({ skill,ob,cast }));
  return 1;
}

int hb_spell(object caster, mixed *params)
{
/*** variables, dependant upon spell ***/
  object armour;
  int enchant;

  if (params[1] != caster)
  {
	 tell_object(caster,
		"Your spell failed ... you may only cast this spell upon yourself.\n");
	 return 0;
  }
  if (params[2] && (int)caster->adjust_gp(-GP_COST)<0)
  {
	 tell_object(caster, "You fail to draw enough power from "
			 "your god.\n");
	 return 0;
  }

  tell_room(environment(caster),(string)caster->query_cap_name()+
	" chants, 'vesios magius arimani'.\n", ({params[1],caster}));


	/** when cast upon self ***  only need altar chant part ***/

	 tell_object(params[1], "You chant, 'vesios magius arimani'.\n");
	 tell_object(params[1], "You cast "+SP_NAME+" upon yourself.\n");
	 tell_room(environment(caster),(string)caster->query_cap_name()+
		" casts a spell upon "+params[1]->query_objective()+"self.\n",params[1]);

  /*** specific spell stuff here ***/

  enchant = ((int)caster->query_level() - 5) / 3;
  
  tell_object(caster,enchant+"\n");

  if (enchant > 4)
   enchant = 4;

  armour = clone_object("/std/spells/cleric/vest_obj.c");
  armour->move(caster);
  armour->vestment_setup(enchant, caster);
  
  return GP_COST;
}
