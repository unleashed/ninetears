/*** Fire Burst Spell ***/
/*** Coded by:  Eerevann Tokani ***/

#define SP_NAME "Fire Burst"
#define GP_COST 2
#define TYPE "fire"
#define save_type "fire"

inherit "/std/spells/patch.c";

/* find_unique_match() does a find match that ensures the returned 
   object list contains no duplicates
   find_one_match() returns only the first matched object
*/
mixed find_unique_match(string find,mixed in);
mixed find_one_match(string find,mixed in);
int wiz_fix_damage(object caster,object victim,int damage,string save);

int ADJ_COST;
object caster;

mixed spell(string str,int skill, int cast);

string help() {
       return
       "\n\n"
       "Spell Name: "+SP_NAME+"\n"
       "School: Invocation and Alteration\n"
       "Level: 1st\n"
       "Gp Cost: "+GP_COST+"\n"
       "Damage Type: "+TYPE+"\n"
       "Saving Throw: 1/2\n"
       "Description: \n"
       "     This spell creates a small burst of flames that envelopes your"
		 " enemies for 1 point for each of your levels.  Maximum damage is"
       " 10.\n";

}


int cast_spell(string str,object cast)
{
  int skill;
  mixed ret;

  if(cast) caster = cast;
  else caster = this_player();

  ret = spell(str, skill, 1);
  if (stringp(ret))
  {
	 notify_fail(ret);
	 return 0;
  }
  tell_object(caster,"You begin to cast "+SP_NAME+".\n");
  tell_room(environment(caster),caster->query_cap_name()+" begins casting an offensive spell.\n",
	caster);
  return 1;
}

mixed spell(string str, int skill, int cast)
{
  mixed ob;
  if ((int)caster->query_spell_effect("offensive"))
	 return "You are already casting an offensive spell.\n";
  ob = find_one_match(str, environment(caster));

  caster->add_spell_effect(1, "offensive", "SP_NAME", this_object(),
    "hb_spell", ({ skill,ob,cast }));
  return 1;
}

int hb_spell(object caster, mixed *params)
{
 int damage;
 string str;
 int NO_OF_DICE;
 int j;
 int i;
 
  /** damage is 1pt  per level of caster, max of 10 **/
  damage = (int)caster->query_level();
  
  if (damage > 10)
		damage = 10;
  
  str = (string)caster->query_cap_name();

  /* to remove the caster, if he uses 'all' */
  if((i = member_array(caster, params[1])) != -1)
    params[1] = delete(params[1], i, 1);
  
  if(!sizeof(params[1])) 
  {
    notify_fail("There is noone here by that name.\n");
    return 0;
  }

   /* Specialists spend only half guild points to cast spells native to their
    * school, so GP_COST is checked and halved, if necessary.     */
  
  ADJ_COST = GP_COST;

  if(interactive(caster) && ((string)caster->query_guild_name() == "invoker" ||
	  (string)caster->query_guild_name() == "transmuter") )
	 ADJ_COST = GP_COST/2;

 if (params[2] && (int)caster->adjust_gp(-ADJ_COST)<0)
 {
  tell_object(caster, "You are currently too "
       "mentally drained to cast.\n");
  return 0;
 }

	tell_room(environment(caster),str+" chants, 'pyros burios'.\n", ({caster,params[1]}));
  tell_object(caster, "You chant, 'pyros burios'.\n");
  
  i = 0;

  while(i<sizeof(params[1])) {
    if(params[1][i] &&
		 environment(params[1][i]) == environment(caster))
    {
		params[1][i]->attack_by(caster);



  params[1][i]->spell_damage(params[1][i],
  wiz_fix_damage(caster, params[1][i],damage,save_type), TYPE,caster);

  tell_object(params[1][i], str + " hits you with a small burst of flame!\n");

		if(params[1][i])
	i++;
      else
	params[1] = delete(params[1], i, 1);
    } else {
      params[1] = delete(params[1], i, 1);
    }
  }

  tell_room(environment(caster),str + " envelopes "+(str = query_multiple_short(params[1]))+
	" with a small burst of flame!\n", ({caster,params[1]}));
  tell_object(caster, "You envelope " + str + " in a Fire "
			"Burst!\n");



  return GP_COST;

}
