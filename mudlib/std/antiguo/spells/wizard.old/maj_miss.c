/*** Major Missile Spell ***/
/*** Created by Eerevann Tokani ***/


#define SP_NAME "Major Missile"
#define GP_COST 10
#define SPELLTYPE "offensive"
#define TYPE "magical"
#define SIZE_OF_DICE 4
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
       "School: Invocation\n"
       "Level: 5th\n"
       "Gp Cost: "+GP_COST+"\n"
       "Damage Type: Magical\n"
		 "Saving Throw: None\n"
		 "Description: \n"
		 "    This spell will send small bolts of energy at the target.  The"
       " bolts do 2-5 points of damage each.  The wizard gets 1 missile "
       "for every 2 levels of experience, up to a maximum of 15 missiles.\n";


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
  tell_room(environment(caster),caster->query_cap_name()+" begins to cast an offensive spell.\n",
	  caster);
  return 1;
  }

mixed spell(string str, int skill, int cast)
{
  mixed ob;

  if ((int)caster->query_spell_effect(SPELLTYPE))
    return "You are already casting an "+SPELLTYPE+" spell.\n";
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
	int i;
 int damage;
 int NO_OF_DICE;

 NO_OF_DICE = ((caster->query_level())+1)/2;

 if(NO_OF_DICE == 0)
	 NO_OF_DICE = 1;

 if (NO_OF_DICE > 15)
    NO_OF_DICE = 15;


  if (!params[1])
  {
	 tell_object(caster,
      "Your spell failed ... there is no one of that name here.\n");
    return 0;
  }
  
	/* Specialists spend only half guild points to cast spells native to their
	 * school, so GP_COST is checked and halved, if necessary.     */

  ADJ_COST = GP_COST;

  if(interactive(caster) &&(string)caster->query_guild_name() == "invoker")
    ADJ_COST = GP_COST/2;
  
  if (params[2] && (int)caster->adjust_gp(-ADJ_COST)<0)
  {
	 tell_object(caster, "You are too mentally drained to cast.\n");
	 return 0;
  }

  tell_room(environment(caster),(string)caster->query_cap_name()+
	" chants, 'majio magyiz myssl'.\n", ({params[1],caster}));
    
  if(params[1] == caster)
	{

   /** when cast upon self ***  only need altar chant part ***/

    tell_object(params[1], "Wouldn't that be suicide?\n");
	 tell_room(environment(caster),(string)caster->query_cap_name()+
		" stops casting.\n",params[1]);
   }
  else
  {
	tell_object(caster, "You chant, 'majio magyiz myssl'.\n");
   
	tell_object(params[1], (string)caster->query_cap_name() +
	 " chants, 'majio magyiz myssl'.\n");
   
   tell_object(params[1], "You are hit by "+NO_OF_DICE+" magic missile(s).\n");
   
	tell_object(caster, "You cast "+SP_NAME+" and hit "+
    (string)params[1]->query_cap_name() + " with "+NO_OF_DICE+
	  " magic missile(s).\n");
   
	tell_room(environment(caster),(string)caster->query_cap_name()+
    " finishes a spell as "+params[1]->query_cap_name()+" is struck by "+
      NO_OF_DICE+" magic missiles(s).\n",
		 ({params[1],caster}) );
  }

  for ( i=1 ; i<=NO_OF_DICE ; i++)
	 damage = damage + random(SIZE_OF_DICE)+2;

  damage = wiz_fix_damage(caster,params[1],damage,save_type);

  params[1]->spell_damage(params[1],damage,TYPE,caster);

  params[1]->attack_by(caster);

  return GP_COST;

}
