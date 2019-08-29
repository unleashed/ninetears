/****  Heal Spell ****/
inherit "/std/spells/patch.c";

/* find_unique_match() does a find match that ensures the returned 
   object list contains no duplicates
   find_one_match() returns only the first matched object
*/
mixed find_unique_match(string find,mixed in);
mixed find_one_match(string find,mixed in);
int cleric_fix_damage(object caster,object victim,int damage,string save);
object caster;
/****  ****/
/**** Modified by Eerevann Tokani ****/

/**** Sphere Healing ***/
/**** Level 6  ***/


/*
 *  Heal: - cure all but 1-4 of a characters hitpoints;
 *        - return all negative temporary stats to zero;
 *        - cure all curses;
 *        - cure all diseases.
 */


#define SP_NAME "Heal"
#define GP_COST 12
#define save_type "magical"

/*** Help file here ***/
string help() {
	return
	"\n\n"
	"Spell Name: "+SP_NAME+"\n"
	"Sphere:  Healing\n"
	"Level:  6th\n"
   "Gp Cost: "+GP_COST+"\n"
   "Description: \n"
     "     Heal is the ultimate healing spell, "
       "cures all but 1-4 points of damage.\n"
       ""
		 "  See Also:\n"
       "      Cure Light Wounds, Cure Serious Wounds, Cure Critical Wounds."
		 "\n";

}


mixed spell(string str, int skill, int cast);
 
int cast_spell(string str,object cast)
  {
  int skill;
  mixed ret;
 
   if(cast) caster = cast;
   else caster = this_player();
   if(interactive(caster))
  str = (string)caster->expand_nickname(str);
  ret = spell(str, skill, 1);
  if (stringp(ret)) {
    notify_fail(ret);
    return 0;
    }
  return 1;
  }
 
mixed spell(string str, int skill, int cast) {
  mixed ob;
 
  if (caster->query_spell_effect("curing"))
    return "You are already casting a curing spell.\n";
  ob = find_one_match(str, environment(caster));
  if (sizeof(ob))
    ob = ob[0];
  else
    ob = 0;
  caster->add_spell_effect(1, "curing", "Full Heal",
    this_object(), "hb_spell", ({ skill,ob,cast }));
  return 1;
  }

int hb_spell(object caster, mixed *params) {
  int i;
int hp;
  mixed *curses;


  if (!params[1]) {
	 tell_object(caster,
      "Your spell fails to find its intended target.\n");
    return 0;
    }
  if (!living(params[1])) {
	 tell_object(caster,
      (string)params[1]->query_cap_name() +
      " is happy with the way it is now and doesnt want any help" 
      " from you.\n");
	 return 0;
    }
  if (params[2] && (int)caster->adjust_gp(-GP_COST) < 0) {
	 tell_object(caster,
      "You feel too drained.\n");
    return 0;
    }
  if (params[1] == caster) {
	 tell_object(caster,
      "You cast a healing spell on yourself and feel a warm" 
      " sensation.  God that felt good!\n");
	 tell_room(environment(caster),
		(string)caster->query_cap_name() +
		" mumbles something and is fully healed.\n", params[1]);
    }
  else {
	 tell_object(caster,
      "You cast a curing spell on " + (string)params[1]->query_cap_name() +
      ", fully healing "+(string)params[1]->query_objective()+".\n");
	 tell_room(environment(caster),
		(string)caster->query_cap_name() +
		" mumbles something then points at " +
		(string)params[1]->query_cap_name() +
		", fully healing "+(string)params[1]->query_objective()+".\n",
		params[1]);
	 tell_object(params[1],
		(string)caster->query_cap_name() +
		" mumbles something then points at you.  You feel a warm" 
		" sensation.  God that felt good!\n");
	 }

  /* fix up hit points */

  hp = params[1]->query_max_hp();
	params[1]->set_hp( hp- (random(4)+1), caster);
    tell_object(params[1], "You feel much healthier.\n");
 
  /* fix up temporary stats */
/**********

  if ((int)params[1]->query_tmp_int() < 0) {
    params[1]->adjust_tmp_int(-((int)params[1]->query_tmp_int()));
    tell_object(params[1], "Your intelligence returns to normal.\n");
    }
  if ((int)params[1]->query_tmp_dex() < 0) {
    params[1]->adjust_tmp_dex(-((int)params[1]->query_tmp_dex()));
    tell_object(params[1], "Your dexterity returns to normal.\n");
	 }
  if ((int)params[1]->query_tmp_wis() < 0) {
    params[1]->adjust_tmp_wis(-((int)params[1]->query_tmp_wis()));
    tell_object(params[1], "Your wisdom returns to normal.\n");
    }
  if ((int)params[1]->query_tmp_str() < 0) {
    params[1]->adjust_tmp_str(-((int)params[1]->query_tmp_str()));
    tell_object(params[1], "Your strength returns to normal.\n");
    }
  if ((int)params[1]->query_tmp_con() < 0) {
	 params[1]->adjust_tmp_con(-((int)params[1]->query_tmp_con()));
    tell_object(params[1], "Your constitution returns to normal.\n");
    }
  params[1]->reset_all();

********/

  /* cure all curses */
/*
  if (sizeof((curses = (mixed *)params[1]->query_curses())))
    for (i=0; i<sizeof(curses); i+=2)
      if (params[1]->query_remove(curses[i])->query_remove(skill)) {
        params[1]->remove_curse(curses[i]);
		  tell_object(params[1], "The curse of " + curses[i] + " is lifted.\n");
      }
*/

  /* cure all diseases */
/*
  if (sizeof((curses = (mixed *)params[1]->query_diseases())))
    for (i=0; i<sizeof(curses); i+=2)
      if (params[1]->query_remove(curses[i])->query_remove(skill)) {
        params[1]->remove_disease(curses[i]);
        tell_object(params[1], "The " + curses[i] + " disease is cured.\n");
      }
 */

  return GP_COST;
  }
