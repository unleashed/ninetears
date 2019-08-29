/*** Cure Serious Wounds Spell ***/
inherit "/d/gremios/hechizos/patch.c";

/* find_unique_match() does a find match that ensures the returned 
   object list contains no duplicates
   find_one_match() returns only the first matched object
*/
mixed find_unique_match(string find,mixed in);
mixed find_one_match(string find,mixed in);
int cleric_fix_damage(object caster,object victim,int damage,string save);
object caster;
/*** Created by Eerevann Tokani ***/


#define SP_NAME "Cure Serious Wounds"
#define GP_COST 8
#define SPELLTYPE "curing"
#define TYPE "magical"
#define SIZE_OF_DICE 8
#define save_type "magical"

 /*** help file ***/
string help() {
       return
		 "\n\n"
       "Spell Name: "+SP_NAME+"\n"
       "Sphere: Healing\n"
       "Level: 4th\n"
       "Gp Cost: "+GP_COST+"\n"
		 "Damage Type: "+TYPE+"\n"
		 "Saving Throw: None\n"
		 "Description: \n"
		 "    This spell will cure 2-16 + 1 points of damage of any target.\n\n";


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

 /******** Notifies Room and Caster that the casting has begun ********/

  tell_object(caster,"You start to cast "+SP_NAME+".\n");
  tell_room(environment(caster),caster->query_cap_name()+" begins to cast a curing spell.\n",
	  caster);
  return 1;
  }

mixed spell(string str, int skill, int cast)
{
  mixed ob;

   /*** CHECKS TO SEE IF CASTER IS CASTING ANOTHER SPELL OF SAME TYPE ***/
   /*** NOT REALLY A FACTOR UNLESS PLAYER IS TRYING TO CAST SEVERAL ***/
   /*** TIMES IN RAPID SUCCESSION ***/
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
 int i;
 int damage;
 int NO_OF_DICE;

 /*** sets up the number of dice to be used in damage calculations ***/
 
 NO_OF_DICE = 2;

   /*** CHECKS TO SEE IF TARGET IS HERE ***/
  if (!params[1])
  {
	 tell_object(caster,
      "Your spell failed ... there is no one of that name here.\n");
    return 0;
  }

   /*** DEDUCTS THE GP COST OF THE SPELL, IF NOT ENOUGH, SPELL FAILS ***/
  if (params[2] && (int)caster->adjust_gp(-GP_COST)<0)
  {
	 tell_object(caster, "You fail to draw enough power from "
       "your god.\n");
    return 0;
  }
    
/*** TELLS ROOM WHAT THE CASTER CHANTS, NOT HEARD BY CASTER OR TARGET ***/
  tell_room(environment(caster),(string)caster->query_cap_name()+
	" chants, 'magius selirs curis'.\n", ({params[1],caster}));
    
  if(params[1] == caster)
   { 
    /*** PREVENTS CASTING OFFENSIVE MAGIC UPON ONES SELF ***/

    tell_object(params[1], "You chant, 'magius selirs curis'.\n");
    tell_object(params[1], "You cure some of your wounds.\n");
	 tell_room(environment(caster),(string)caster->query_cap_name()+
		 " cures some of "+caster->query_possessive()+" wounds.\n");
   }
  else
  {
    /*** TELL CASTER WHAT HE CHANTS ***/
	tell_object(caster, "You chant, 'magius selirs curis'.\n");
   
    /*** TELL TARGET WHAT CASTER CHANTS ***/
	tell_object(params[1], (string)caster->query_cap_name() +
    " chants, 'magius selirs curis'.\n");
   
    /*** TELL TARGET WHAT HAPPENS TO HIM AFTER SPELL GOES OFF ***/
	tell_object(params[1], (string)caster->query_cap_name()+
      " touches you healing several of your wounds.\n");
   
    /*** TELL CASTER THE EFFECTS OF HIS SPELL AND WHO IT HIT ***/
	tell_object(caster, "You cast "+SP_NAME+" at "+
    (string)params[1]->query_cap_name() + ".\n");
   
    /*** TELLS ROOM THE EFFECTS OF THE SPELL BUT NOT CASTER OR TARGET ***/
	tell_room(environment(caster),(string)caster->query_cap_name()+
    " casts a spell and cures several of "+params[1]->query_cap_name()+
      "'s wounds.\n",
		 ({params[1],caster}) );
  }

   /*** FOR LOOP TO RANDOMLY GENERATE DAMAGE, NO_OF_DICE(D)SIZE_OF_DICE ***/
   /*** 1d4 = 1 to 4 damage, or 1d6 = 1-6 damage, 6d6 would be 6-36, etc ***/
  for ( i=1 ; i<=NO_OF_DICE ; i++)
    damage = damage + random(SIZE_OF_DICE)+1;
    damage = damage + 1;

  damage = cleric_fix_damage(caster,params[1],damage,save_type);

  params[1]->adjust_hp(damage,caster);

	/*** GIVES EXP TO CASTER EQUAL TO THE VALUE RETURNED ***/
  return GP_COST;

}
