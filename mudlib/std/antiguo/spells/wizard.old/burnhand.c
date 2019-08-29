/*** Burning Hands Spell ***/
/*** Created by Eerevann Tokani ***/
/*     Cosmetics by Aarn'Kii  --  03/94     */
/* working with NPC's Taniwha '95 */

#define SP_NAME "Burning Hands"
#define GP_COST 2
#define SPELLTYPE "offensive"
#define TYPE "fire"
#define SIZE_OF_DICE 3
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

 /*** help file ***/
string help() {
		 return
       "\n\n"
       "Spell Name: "+SP_NAME+"\n"
       "School: Alteration\n"
		 "Level: 1st\n"
       "Gp Cost: "+GP_COST+"\n"
		 "Damage Type: "+TYPE+"\n"
		 "Saving Throw: 1/2\n"
		 "Description: \n"
		 "    When cast, a jet of flame shoots from the caster's fingertips "
		 "to the target.  Damage done is 1d3 points + 2 points per level of "
		 "the caster, to a maximum of 1d3+20 points.\n";


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

 /******** Notifies Room and Caster that the casting has begun ********/

  tell_object(caster,"You start to cast "+SP_NAME+".\n");
  say(caster->query_cap_name()+" begins to cast an offensive spell.\n",
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
 
 int damage;
 int NO_OF_DICE;
 int level;
 
 /*** sets up the number of dice to be used in damage calculations ***/
 
 NO_OF_DICE = 1;

   /*** CHECKS TO SEE IF TARGET IS HERE ***/
   if(!params[1] || ! present(params[1],environment(caster) ) )
  {
	 tell_object(caster,
      "Your spell failed ... there is no one of that name here.\n");
    return 0;
  }

   /*** DEDUCTS THE GP COST OF THE SPELL, IF NOT ENOUGH, SPELL FAILS ***/
	/* Specialists spend only half guild points to cast spells native to their
    * school, so GP_COST is checked and halved, if necessary.     */
  ADJ_COST = GP_COST;
  if(interactive(caster) && (string)caster->query_guild_name() == "transmuter")
	 ADJ_COST = GP_COST/2;
  if (params[2] && (int)caster->adjust_gp(-ADJ_COST)<0)
  {
	 tell_object(caster, "You are too mentally drained to cast.\n");
	 return 0;
  }
    
/*** TELLS ROOM WHAT THE CASTER CHANTS, NOT HEARD BY CASTER OR TARGET ***/
  tell_room(environment(caster),(string)caster->query_cap_name()+
	" chants, \"flamius os aryes.\"\n",({params[1],caster}));
    
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
	tell_object(caster, "You chant, \"flamius os aryes.\"\n");
   
    /*** TELL TARGET WHAT CASTER CHANTS ***/
	tell_object(params[1], (string)caster->query_cap_name() +
    " chants, \"flamius os aryes.\"\n");
   
    /*** TELL TARGET WHAT HAPPENS TO HIM AFTER SPELL GOES OFF ***/
	tell_object(params[1],(string)caster->query_cap_name()+
		" brings "+caster->query_possessive()+" hands together, and "
      "the air around them flashes into a brilliant jet of flames that "
      "envelopes you.\n");
   
    /*** TELL CASTER THE EFFECTS OF HIS SPELL AND WHO IT HIT ***/
	tell_object(caster,"You send a large jet of flames into "+
    (string)params[1]->query_cap_name()+"'s midsection.\n");
   
    /*** TELLS ROOM THE EFFECTS OF THE SPELL BUT NOT CASTER OR TARGET ***/
	tell_room(environment(caster),"An arc of flame erupts from "+caster->query_cap_name()+
    "'s hands, blanketing "+params[1]->query_cap_name()+" in fire.\n",
		({caster,params[1]}));
  }

    /** damage is 1d3 + (level*2) max of 1d3+20 **/

	 level = (int)caster->query_level();

	 if (level > 10)
		level = 10;

	 damage = damage + random(SIZE_OF_DICE) + 1 + (level*2);

	/*** SENDS INFO TO SAVING THROW ROUTINE IN SPELLS.C, IF VICTIM MAKES ***/
	/* damage based on casters int relative to nominal, and victims property based save */
  damage = wiz_fix_damage(caster,params[1],damage,save_type);

	/*** SENDS INFO TO DAMAGE ROUTINE IN SPELLS.C TO DO DAMAGE TO TARGET ***/
  params[1]->spell_damage(params[1],damage,TYPE,caster);

	/*** STARTS COMBAT BETWEEN TARGET AND CASTER ***/
  params[1]->attack_by(caster);

	/*** GIVES EXP TO CASTER EQUAL TO THE VALUE RETURNED ***/
  return GP_COST;

}
