/*** Light Spell ***/
/*** Created by Eerevann Tokani ***/


#define SP_NAME "Light"
#define GP_COST 2
#define SPELLTYPE "misc"

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
       "School: Alteration\n"
		 "Level: 1st\n"
       "Gp Cost: "+GP_COST+"\n"
       "Description: \n"
		 "    This spell creates light allowing you to see in dark rooms.\n\n";
       

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


  if (!params[1])
  {
	 tell_object(caster,
      "Your spell failed ... there is no one of that name here.\n");
	 return 0;
  }
   
	/* Specialists spend only half guild points to cast spells native to their
	 * school, so GP_COST is checked and halved, if necessary.     */

  ADJ_COST = GP_COST;

  if(interactive(caster)&&(string)caster->query_guild_name() == "transmuter")
	 ADJ_COST = GP_COST/2;

  if (params[2] && (int)caster->adjust_gp(-ADJ_COST)<0)
  {
	 tell_object(caster, "You are too mentally drained to cast.\n");
	 return 0;
  }

  tell_room(environment(caster),(string)caster->query_cap_name()+
	" chants, 'blah blah blah'.\n", ({params[1],caster}));
    
  if(params[1] == caster)
   { 

   /** when cast upon self ***  only need altar chant part ***/

	 tell_object(params[1], "You chant, 'magius lios'.\n");
    tell_object(params[1], "You cast "+SP_NAME+" upon yourself.\n");
	 tell_room(environment(caster),(string)caster->query_cap_name()+
      " casts a spell upon "+params[1]->query_objective()+"self.\n",params[1]);
   }
  else
  {
	tell_object(caster, "You chant, 'magius lios'.\n");
   
	tell_object(params[1], (string)caster->query_cap_name() +
    " chants, 'maguis lios'.\n");
   
	tell_object(params[1], (string)caster->query_cap_name() +
		" casts light on you.\n");
   
	tell_object(caster, "You cast "+SP_NAME+" on "+
    (string)params[1]->query_cap_name() + ".\n");
   
	tell_room(environment(caster),(string)caster->query_cap_name()+
    " casts a light upon "+params[1]->query_cap_name()+".\n",
		 ({params[1],caster}) );
  }

  /*** specific spell stuff here ***/
   
   params[1]->set_light(60);
   call_out("wear_off",100+((params[1]->query_level())+400), params[1]);

 return GP_COST;
}

void wear_off(object target)
{
 target->set_light(0);
 tell_object(target,"Your globe of light disappears.\n");
 tell_room(environment(target),target->query_cap_name()+"'s globe of light disappears.\n",target);
}
