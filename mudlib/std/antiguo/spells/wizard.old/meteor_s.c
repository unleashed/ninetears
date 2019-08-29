/*** Meteor Swarm Spell ***/
/*** Coded by:  Eerevann Tokani ***/

#define SP_NAME "Meteor Swarm"
#define GP_COST 18
#define TYPE "fire"
#define SIZE_OF_DICE 4
#define save_type "spells"

inherit "/std/spells/patch.c";

/* find_unique_match() does a find match that ensures the returned 
   object list contains no duplicates
   find_one_match() returns only the first matched object
*/
mixed find_unique_match(string find,mixed in);
mixed find_one_match(string find,mixed in);
int ADJ_COST;

mixed spell(string str,int skill, int cast);

string help() {
       return
       "\n\n"
       "Spell Name: "+SP_NAME+"\n"
       "School: Invocation\n"
       "Level: 9th\n"
       "Gp Cost: "+GP_COST+"\n"
       "Damage Type: "+TYPE+"\n"
       "Saving Throw: 1/2\n"
       "Description: \n"
       "     This spell will envelope your enemies in a fiery shower of "
       "meteors which expode upon impact.  The damage is 40-160 points "
       "damage.\n\n";

}


int cast_spell(string str)
{
  int skill;
  mixed ret;

  ret = spell(str, skill, 1);
  if (stringp(ret))
  {
    notify_fail(ret);
    return 0;
  }
  write("You begin to cast "+SP_NAME+".\n");
  say(this_player()->query_cap_name()+" begins casting an offensive spell.\n",
	this_player());
  return 1;
}

mixed spell(string str, int skill, int cast)
{
  mixed ob;
  if ((int)this_player()->query_spell_effect("offensive"))
    return "You are already casting an offensive spell.\n";
  ob = find_unique_match(str, environment(this_player()));

  this_player()->add_spell_effect(2, "offensive", "SP_NAME", this_object(),
    "hb_spell", ({ skill,ob,cast }));
  return 1;
}

int hb_spell(object caster, mixed *params, int time)
{
 int damage;
 string str;
 int NO_OF_DICE;
 int j;
 int i;
 
 NO_OF_DICE = 40;

  if ( time == 2 )
  {
    tell_object(caster, "4 flaming spheres of molten rock appear in the air before you.\n");
    tell_room(environment(caster), "4 flaming balls of molten rock form in the air in front of "+
    caster->query_cap_name()+".\n", caster);
    return 1;
  }
  
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
  
  if((string)caster->query_guild_name() == "invoker")
    ADJ_COST = GP_COST/2;
  
 if (params[2] && (int)caster->adjust_gp(-ADJ_COST)<0)
 {
  tell_object(caster, "You are currently too "
       "mentally drained to cast.\n");
  return 0;
 }

  tell_room(environment(caster), str+" chants, 'meseious pyros blasious'.\n\n"+
    str+" makes a gesture and the meteors streak toward their targets!\n", ({ caster, params[1] }) );
  tell_object(caster, "You chant, 'meseious pyros blasious'.\n");
  
  i = 0;
  while(i<sizeof(params[1])) {
  damage = 0;
    if(params[1][i] &&
       environment(params[1][i]) == environment(caster))
    {
      params[1][i]->attack_by(caster);

  for ( j=1 ; j<=NO_OF_DICE ; j++)
    damage = damage + random(SIZE_OF_DICE)+1;

  damage = params[1][i]->spell_saving_throw(params[1][i],damage,save_type);

  params[1][i]->spell_damage(params[1][i],damage,TYPE,caster);

  tell_object(params[1][i], str + " envelopes you in a fiery meteor shower!\n");

      if(params[1][i])
	i++;
      else
	params[1] = delete(params[1], i, 1);
    } else {
      params[1] = delete(params[1], i, 1);
    }
  }

  say(str + " envelopes "+(str = query_multiple_short(params[1]))+
   " in a fiery meteor shower!\n", ({caster,params[1]}));
  tell_object(caster, "You envelope " + str + " in a "
   " in a fiery meteor shower!\n");

   

  return GP_COST;

}
