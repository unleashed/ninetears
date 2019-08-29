/*** Minor Acid Protection Spell ***/
/*** Created by Eerevann Tokani ***/


#define SP_NAME "Minor Magical Resistance"
#define GP_COST 6
#define TYPE "magical"
#define save_type "magical"

inherit "/std/spells/patch.c";

/* find_unique_match() does a find match that ensures the returned 
   object list contains no duplicates
	find_one_match() returns only the first matched object
*/
mixed find_unique_match(string find,mixed in);
mixed find_one_match(string find,mixed in);
int wiz_fix_damage(object caster,object victim,int damage,string save);
object caster;
int ADJ_COST;

string help() {
       return
		 "\n\n"
       "Spell Name: "+SP_NAME+"\n"
       "School: Abjuration\n"
		 "Level: 3rd\n"
       "Gp Cost: "+GP_COST+"\n"
		 "Description: \n"
       "    This spell reduces damage done by Acid based attacks "
       "by 25% plus +1% per level of the caster.\n"
       "    The duration is based upon the casters level.\n";


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

  if ((int)caster->query_spell_effect("defensive"))
	 return "You are already casting an defensive spell.\n";
  ob = find_one_match(str, environment(caster));
  if (sizeof(ob))
    ob = ob[0];
  else
    ob = 0;

  caster->add_spell_effect(1, "defensive", SP_NAME,
    this_object(), "hb_spell", ({ skill,ob,cast }));
  return 1;
}

int hb_spell(object caster, mixed *params)
{
  int resist_value;
  int level;

  if (!params[1])
  {
	 tell_object(caster,
      "Your spell failed ... there is no one of that name here.\n");
    return 0;
  }
  
   /* Specialists spend only half guild points to cast spells native to their
    * school, so GP_COST is checked and halved, if necessary.     */

  ADJ_COST = GP_COST;
  
  if(interactive(caster) &&(string)caster->query_guild_name() == "abjurer")
    ADJ_COST = GP_COST/2;
  
  if (params[2] && (int)caster->adjust_gp(-ADJ_COST)<0)
  {
	 tell_object(caster, "You are too mentally drained to cast.\n");
    return 0;
  }
    
  tell_room(environment(caster),(string)caster->query_cap_name()+
	" chants, 'mior corozev rissas'.\n", ({params[1],caster}));
    
  if(params[1] == caster)
   { 
    tell_object(params[1], "You chant, 'mior corozev rissas'.\n");
    tell_object(params[1], "You cast "+SP_NAME+" upon yourself.\n");
	 tell_room(environment(caster),(string)caster->query_cap_name()+
      " casts a spell upon "+params[1]->query_objective()+"self.\n",params[1]);
   }
  else
  {
	tell_object(caster, "You chant, 'mior corozev rissas'.\n");
   
	tell_object(params[1], (string)caster->query_cap_name() +
    " chants, 'mior corozev rissas'.\n");
   
   tell_object(params[1], "You feel slightly resistant to Acid attacks.\n");
   
	tell_object(caster, "You cast "+SP_NAME+" on "+
    (string)params[1]->query_cap_name() + ".\n");
   
	tell_room(environment(caster),(string)caster->query_cap_name()+
    " casts a spell upon "+params[1]->query_cap_name()+".\n",
		 ({params[1],caster}) );
  }

  level = (int)caster->query_level();
  resist_value = level + 25;

	params[1]->add_timed_property(TYPE,resist_value,50+(level*4));
  return GP_COST;
}

