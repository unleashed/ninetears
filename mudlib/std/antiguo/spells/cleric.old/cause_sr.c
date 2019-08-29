/*** Cause Serious Wounds Spell ***/
inherit "/std/spells/patch.c";

/* find_unique_match() does a find match that ensures the returned 
   object list contains no duplicates
   find_one_match() returns only the first matched object
*/
mixed find_unique_match(string find,mixed in);
mixed find_one_match(string find,mixed in);
int cleric_fix_damage(object caster,object victim,int damage,string save);
object caster;
/*** Created by Eerevann Tokani ***/


#define SP_NAME "Cause Serious Wounds"
#define GP_COST 8
#define SPELLTYPE "offensive"
#define TYPE "magical"
#define SIZE_OF_DICE 8
#define save_type "magical"

 /*** help file ***/
string help() {
		 return
       "\n\n"
       "Spell Name: "+SP_NAME+"\n"
       "Sphere: Healing (reversed)\n"
       "Level: 4th\n"
       "Gp Cost: "+GP_COST+"\n"
		 "Damage Type: "+TYPE+"\n"
		 "Saving Throw: None\n"
       "Description: \n"
       "    This spell will do 2-16 + 1 points of damage to an enemy of your "
       "choice.  The spell, once cast, requires the caster to touch the "
       "target.  If the touch misses, the spell's energy is wasted.\n\n";


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
  tell_room(environment(caster),caster->query_cap_name()+" begins to cast an offensive spell.\n",
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
 int level;
 int ac;
 int ac_hit;
 int thaco;
 int roll;

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
    
 /** sets up to-hit data **/

thaco = (int)caster->query_thac0();
 roll = random(20)+1;
 ac_hit = thaco-roll;


/*** TELLS ROOM WHAT THE CASTER CHANTS, NOT HEARD BY CASTER OR TARGET ***/
  tell_room(environment(caster),(string)caster->query_cap_name()+
	" chants, 'magius selirs harmei'.\n", ({params[1],caster}));
    
  if(params[1] == caster)
   { 
    /*** PREVENTS CASTING OFFENSIVE MAGIC UPON ONES SELF ***/

    tell_object(params[1], "Wouldn't that be suicide?\n");
	 tell_room(environment(caster),(string)caster->query_cap_name()+
      " stops casting.\n",params[1]);
   }
  else
  {
    /*** TELL CASTER WHAT HE CHANTS ***/
	tell_object(caster, "You chant, 'magius selirs harmei'.\n");
   
    /*** TELL TARGET WHAT CASTER CHANTS ***/
	tell_object(params[1], (string)caster->query_cap_name() +
    " chants, 'magius selirs harmei'.\n");
   
	if((random((int)caster->query_thac0()) + params[1]->query_total_ac()) > 0)
	{
    /*** TELL TARGET WHAT HAPPENS TO HIM AFTER SPELL GOES OFF ***/
	tell_object(params[1], (string)caster->query_cap_name()+
      " reaches out and touches you as several cuts appear on you.\n");

    /*** TELL CASTER THE EFFECTS OF HIS SPELL AND WHO IT HIT ***/
	tell_object(caster, "You cast "+SP_NAME+" and touch "+
    (string)params[1]->query_cap_name() + " causing several cuts.\n");
   
    /*** TELLS ROOM THE EFFECTS OF THE SPELL BUT NOT CASTER OR TARGET ***/
	tell_room(environment(caster),(string)caster->query_cap_name()+
    " casts a spell and touches "+params[1]->query_cap_name()+" causing "
    "several cuts.\n",
		 ({params[1],caster}) );
    } //end if
  else //if they miss
    {
	 /*** TELL TARGET WHAT HAPPENS TO HIM AFTER SPELL GOES OFF ***/
	tell_object(params[1], (string)caster->query_cap_name()+
		" reaches out and trys to touch you, missing.\n");

    /*** TELL CASTER THE EFFECTS OF HIS SPELL AND WHO IT HIT ***/
	tell_object(caster, "You cast "+SP_NAME+" and try to touch "+
    (string)params[1]->query_cap_name() + ", missing.\n");
   
    /*** TELLS ROOM THE EFFECTS OF THE SPELL BUT NOT CASTER OR TARGET ***/
	tell_room(environment(caster),(string)caster->query_cap_name()+
    " casts a spell and trys to touches "+params[1]->query_cap_name()+
	 ", missing.\n",
		 ({params[1],caster}) );
     return 1;
	}
  

  }

   /*** FOR LOOP TO RANDOMLY GENERATE DAMAGE, NO_OF_DICE(D)SIZE_OF_DICE ***/
   /*** 1d4 = 1 to 4 damage, or 1d6 = 1-6 damage, 6d6 would be 6-36, etc ***/
  for ( i=1 ; i<=NO_OF_DICE ; i++)
    damage = damage + random(SIZE_OF_DICE)+1;
    damage = damage + 1;

  damage = cleric_fix_damage(caster,params[1],-damage,save_type);

  /*** SENDS INFO TO DAMAGE ROUTINE IN SPELLS.C TO DO DAMAGE TO TARGET ***/
   params[1]->adjust_hp(damage,caster);

   /*** STARTS COMBAT BETWEEN TARGET AND CASTER ***/
  params[1]->attack_by(caster);

   /*** GIVES EXP TO CASTER EQUAL TO THE VALUE RETURNED ***/
  return GP_COST;

}
