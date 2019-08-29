
/*** Vampiric Touch Spell ***/
/*** Created by Eerevann Tokani ***/


#define SP_NAME "Vampiric Touch"
#define GP_COST 6
#define SPELLTYPE "offensive"
#define TYPE "magical"
#define SIZE_OF_DICE 6
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

 /*** help file ***/
string help() {
		 return
		 "\n\n"
		 "Spell Name: "+SP_NAME+"\n"
		 "School: Necromancy\n"
		 "Level: 3rd\n"
       "Gp Cost: "+GP_COST+"\n"
		 "Damage Type: "+TYPE+"\n"
       "Saving Throw: None\n"
       "Description: \n"
       "    This spell allows the caster to drain hit points from a target"
       "and transfer them to himself.  The caster gets one half the "
       "hit points drained transfer to him.  The caster may not exceed his "
       "normal maximum of hit points.  The damage done is 1d6 "
		 "for each 2 levels of the caster with a maximum of 6d6 at 12th "
       "level.  Undead creatures are not affected by this spell.\n";
       

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
  
  ob = find_unique_match(str, environment(caster));
  if (sizeof(ob))
    ob = ob[0];
  else
    ob = 0;

  caster->add_spell_effect(2, SPELLTYPE, SP_NAME,
    this_object(), "hb_spell", ({ skill,ob,cast }));
  return 1;
}

int hb_spell(object attacker, mixed *params, int time)
{
 
 int i;
 int damage;
 int NO_OF_DICE;

  if ( time == 2 )
  {
    tell_object(caster, "You open a conduit to the Negative Material "
      "Plane.\n");
    tell_room(environment(caster), caster->query_cap_name()+
    " creates a pinprick of absolute void before "+
      caster->query_objective()+".\n", caster);
    return 1;
  }
 /*** sets up the number of dice to be used in damage calculations ***/
 
 NO_OF_DICE = (((int)caster->query_level())/2);

 if(NO_OF_DICE == 0)
    NO_OF_DICE = 1;

 if (NO_OF_DICE > 6)
    NO_OF_DICE = 6;

   /*** CHECKS TO SEE IF TARGET IS HERE ***/
  if (!params[1])
  {
	 tell_object(caster,
      "Your spell failed ... there is no one of that name here.\n");
    return 0;
  }

   /*** DEDUCTS THE GP COST OF THE SPELL, IF NOT ENOUGH, SPELL FAILS ***/
   /* Specialists spend only half guild points to cast spells native to their
    * school, so GP_COST is checked and halved, if necessary.     */
  
  ADJ_COST = GP_COST;
  
  if(interactive(caster) &&(string)caster->query_guild_name() == "necromancer")
	 ADJ_COST = GP_COST/2;

  if (params[2] && (int)caster->adjust_gp(-ADJ_COST)<0)
  {
	 tell_object(caster, "You are too mentally drained to cast.\n");
	 return 0;
  }

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
	tell_object(caster, "You chant, 'gimme ye helth'.\n");
   
    /*** TELL TARGET WHAT CASTER CHANTS ***/
	tell_object(params[1], (string)caster->query_cap_name() +
    " chants, 'gimme ye helth'.\n");
   

 /** STOPS CASTING IF CREATURE IS UNDEAD, BUT STILL COSTS GP :) ***/    
  if (!living(params[1]) )
  {
    tell_object(caster, "You need to cast this on living things.\n");
    return 0;
  }
   if (params[1]->query_property("undead"))
    {  
		tell_object(caster, "You can't cast this on an undead!\n");
	 tell_room(environment(caster),(string)caster->query_cap_name()+
	  " stops casting the spell.\n",caster);
      return 0;
    } 

    /*** TELL TARGET WHAT HAPPENS TO HIM AFTER SPELL GOES OFF ***/
	tell_object(params[1], (string)caster->query_cap_name()+
    " motions the pinprick of void toward you!\n\n"
    "As it touches you, you feel life surge out of you, and see "+
    caster->query_cap_name()+" look refreshed.\n");
   
    /*** TELL CASTER THE EFFECTS OF HIS SPELL AND WHO IT HIT ***/
  tell_object(caster, "You motion the pinprick of Negative Material energy toward "+
    params[1]->query_cap_name()+" and \nfeel the vitality surge "
    "into you as the colour drains from "+params[1]->query_possessive()+
    "face.\n");
   
    /*** TELLS ROOM THE EFFECTS OF THE SPELL BUT NOT CASTER OR TARGET ***/
	tell_room(environment(caster),(string)caster->query_cap_name()+
    " motions the pinprick of blackness toward "+params[1]->query_cap_name()+" as "
    " lifeforce seems to pass between the two.\n",
		 ({params[1],caster}) );
  }

   /*** FOR LOOP TO RANDOMLY GENERATE DAMAGE, NO_OF_DICE(D)SIZE_OF_DICE ***/
   /*** 1d4 = 1 to 4 damage, or 1d6 = 1-6 damage, 6d6 would be 6-36, etc ***/
  for ( i=1 ; i<=NO_OF_DICE ; i++)
    damage = damage + random(SIZE_OF_DICE)+1;


  damage = wiz_fix_damage(caster,params[1],damage,save_type);
   if(params[1]->query_property("undead") ) damage = -damage;

/*** SENDS INFO TO DAMAGE ROUTINE IN SPELLS.C TO DO DAMAGE TO TARGET ***/
  params[1]->spell_damage(params[1],damage,TYPE,caster);
  caster->adjust_hp(damage/2); /** heals caster for half
															 damage done ***/

	/*** STARTS COMBAT BETWEEN TARGET AND CASTER ***/
  params[1]->attack_by(caster);

   /*** GIVES EXP TO CASTER EQUAL TO THE VALUE RETURNED ***/
  return GP_COST;

}

