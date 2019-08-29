/*** Fireball Spell ***/
/*** Coded by:  Eerevann Tokani ***/

#define SP_NAME "fireball"
#define GP_COST 6
#define TYPE "fire"
#define SIZE_OF_DICE 6
#define save_type "spells"
void hb_spell(object ob, mixed * params);
int hbb_spell(mixed * params);
int hbb1_spell(mixed *params);

int ADJ_COST;
object caster;

inherit "/std/spells/patch.c";

/* find_unique_match() does a find match that ensures the returned 
   object list contains no duplicates
   find_one_match() returns only the first matched object
*/
mixed find_unique_match(string find,mixed in);
mixed find_one_match(string find,mixed in);
mixed spell(string str,int skill, int cast);

string help() {
       return
       "\n\n"
       "Spell Name: "+SP_NAME+"\n"
       "School: Invocation\n"
       "Level: 3rd\n"
       "Gp Cost: "+GP_COST+"\n"
       "Damage Type: "+TYPE+"\n"
       "Saving Throw: 1/2\n"
       "Description: \n"
       "     This spell envelopes a group of enemies in a ball of fire.  "
       "The damage caused is equal to the level of the caster d6, with "
       "a maximum of 10d6.\n";

}


int cast_spell(string str,object who)
{
  int skill;
  mixed ret;

   if(who) caster = who;
   else caster = this_player();
  ret = spell(str, skill, 1);
  if (stringp(ret))
  {
    tell_room(environment(caster),ret);
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
  ob = find_unique_match(str, environment(caster));

 caster->add_spell_effect(1, "offensive", SP_NAME, this_object(),
   "hb_spell", ({ skill,ob,cast }));
//    hbb_spell(({skill,ob,cast}));
  return 1;
}

int hb_spell(object caster, mixed *params)
{
 int damage;
 string str;
 int NO_OF_DICE;
   int j;
 int i;

 NO_OF_DICE = caster->query_level();

 if(NO_OF_DICE == 0)
    NO_OF_DICE = 1;

 if (NO_OF_DICE > 10)
    NO_OF_DICE = 10;
  
  str = (string)caster->query_cap_name();

  /* to remove the caster, if he uses 'all' */
  if((i = member_array(caster, params[1])) != -1)
    params[1] = delete(params[1], i, 1);
  
  if(!sizeof(params[1])) 
  {
    tell_room(environment(caster),"There is noone here by that name.\n");
    return 0;
  }
   
   /* Specialists spend only half guild points to cast spells native to their
    * school, so GP_COST is checked and halved, if necessary.     */
  
  ADJ_COST = GP_COST;
  
   if( interactive(caster) )
  if((string)caster->query_guild_name() == "invoker")
    ADJ_COST = GP_COST/2;

 if (params[2] && (int)caster->adjust_gp(-ADJ_COST)<0)
 {
  tell_object(caster, "You are currently too "
       "mentally drained to cast.\n");
  return 0;
 }

  tell_room(environment(caster),str + " chants, 'pyros os sphyris'.\n", caster);
  tell_object(caster, "You chant, 'pyros os sphyris'.\n");
  
  i = 0;
  while(i<sizeof(params[1])) {
    if(params[1][i] &&
       environment(params[1][i]) == environment(caster))
    {
      params[1][i]->attack_by(caster);

   damage = 0;
  for ( j=1 ; j<=NO_OF_DICE ; j++)
    damage = damage + random(SIZE_OF_DICE);

  damage = wiz_fix_damage(caster,params[1][i],damage,save_type);

  params[1][i]->spell_damage(params[1][i],damage,TYPE,caster);

  tell_object(params[1][i], str + " hits you with a Fireball!\n");

      if(params[1][i])
	i++;
      else
	params[1] = delete(params[1], i, 1);
    } else {
      params[1] = delete(params[1], i, 1);
    }
  }

  tell_room(environment(caster),str + " envelopes "+(str = query_multiple_short(params[1]))+
   " in a Fireball!\n", ({caster,params[1]}));
  tell_object(caster, "You envelope " + str + " in a Fireball!\n");

  return GP_COST;

}
int hbb_spell(mixed *params)
{
   call_out("hbb1_spell",5,params);
}
int hbb1_spell(mixed *params)
{
    hb_spell(caster,params);
}
