/*** Shadow Magic Lightning Bolt Spell ***/          
/*** Created by Eerevann Tokani ***/


#define SP_NAME "Shadow Magic Lightning Bolt"
#define GP_COST 10
#define SPELLTYPE "offensive"
#define TYPE "electrical"
#define SIZE_OF_DICE 6
#define save_type "spells"

inherit "/std/spells/patch.c";

/* find_unique_match() does a find match that ensures the returned 
   object list contains no duplicates
   find_one_match() returns only the first matched object
*/
mixed find_unique_match(string find,mixed in);
mixed find_one_match(string find,mixed in);
int ADJ_COST;

 /*** help file ***/
string help() {
       return
       "\n\n"
       "Spell Name: "+SP_NAME+"\n"
       "School: Illusion\n"
       "Level: 5th\n"
       "Gp Cost: "+GP_COST+"\n"
       "Damage Type: "+TYPE+"\n"
       "Saving Throw: Special\n"
       "Description: \n"
       "    This spell is one of the Shadow Magic spells.  "
       "Shadow Magic channels in energy from the Shadow Plane to make "
       "quasi-real wizard spells.  "
       "The spell "
       "creates the illusion of a lightning bolt that strikes the target "
       "doing (level)d6 with a maximum of 10d6 damage (the target gets "
       "a saving throw for half damage).  The target gets "
       "a saving throw to detect the illusion.  If he fails this saving "
       "throw, the spell works with the normal effects.  If the target "
       "makes his save (detecting the illusion) the shadow magic only does "
       "20% of normal damage.\n"
       "    Example:  10th level Caster casts Shadow Magic Lightning Bolt "
       "at Target."
       "  Target misses the saving throw and thinks its real.  Target will "
       "take 10d6 damage or 5d6 (if he makes a second saving throw).\n";
       

}

mixed spell(string str, int skill, int cast);

int cast_spell(string str)
{
  int skill;
  mixed ret;

  str = (string)this_player()->expand_nickname(str);
  
  ret = spell(str, skill, 1);
  if (stringp(ret))
  {
    notify_fail(ret);
    return 0;
  }

 /******** Notifies Room and Caster that the casting has begun ********/

  write("You start to cast "+SP_NAME+".\n");
  say(this_player()->query_cap_name()+" begins to cast an offensive spell.\n",
     previous_object());
  return 1;
  }

mixed spell(string str, int skill, int cast)
{
  mixed ob;

   /*** CHECKS TO SEE IF CASTER IS CASTING ANOTHER SPELL OF SAME TYPE ***/
   /*** NOT REALLY A FACTOR UNLESS PLAYER IS TRYING TO CAST SEVERAL ***/
   /*** TIMES IN RAPID SUCCESSION ***/
  if ((int)this_player()->query_spell_effect(SPELLTYPE))
    return "You are already casting an "+SPELLTYPE+" spell.\n";
  
  ob = find_one_match(str, environment(this_player()));
  if (sizeof(ob))
    ob = ob[0];
  else
    ob = 0;

  this_player()->add_spell_effect(1, SPELLTYPE, SP_NAME,
    this_object(), "hb_spell", ({ skill,ob,cast }));
  return 1;
}

int hb_spell(object caster, mixed *params)
{
 
  int wizthiefbonus;
 int i;
 int damage;
 int NO_OF_DICE;
 int DETECTED;

 DETECTED = 0;

 /*** sets up the number of dice to be used in damage calculations ***/
 
 NO_OF_DICE = this_player()->query_level();

 if(NO_OF_DICE == 0)
    NO_OF_DICE = 1;

 if (NO_OF_DICE > 10)
    NO_OF_DICE = 10;

   /*** CHECKS TO SEE IF TARGET IS HERE ***/
  if (!params[1])
  {
    tell_object(this_player(),
      "Your spell failed ... there is no one of that name here.\n");
    return 0;
  }

   /*** DEDUCTS THE GP COST OF THE SPELL, IF NOT ENOUGH, SPELL FAILS ***/
  
   /* Specialists spend only half guild points to cast spells native to their
    * school, so GP_COST is checked and halved, if necessary.     */
  
  ADJ_COST = GP_COST;
  
  if((string)previous_object()->query_guild_name() == "illusionist" ||
    (string)previous_object()->query_guild_name() == "wizthief")
  {
    wizthiefbonus=(int)previous_object()->query_level();
    ADJ_COST = GP_COST/2;
  }
  
  if (params[2] && (int)previous_object()->adjust_gp(-ADJ_COST)<0)
  {
    tell_object(previous_object(), "You are too mentally drained to cast.\n");
    return 0;
  }
    

/*** TELLS ROOM WHAT THE CASTER CHANTS, NOT HEARD BY CASTER OR TARGET ***/
  say((string)previous_object()->query_cap_name()+
   " chants, 'xlxyx de gadrum'.\n", ({params[1],previous_object()}));
    
  /** saving throw for shadow magic detection **/
  if ( random((int)caster->query_level()) + wizthiefbonus <=
    random((int)params[1]->query_int()) )
   {
     tell_object(previous_object(), (string)params[1]->query_cap_name()+
       " detects your illusion!\n");

     DETECTED = 1;

     tell_object(params[1], "You realize that "+
       (string)previous_object()->query_cap_name()+"'s spell is only an "
       "illusion and disbelieve most of the damage!\n");
   }

  if(params[1] == previous_object())
   { 
    /*** PREVENTS CASTING OFFENSIVE MAGIC UPON ONES SELF ***/

    tell_object(params[1], "Wouldn't that be suicide?\n");
    say((string)previous_object()->query_cap_name()+
      " stops casting.\n",params[1]);
   }
  else
  {
    /*** TELL CASTER WHAT HE CHANTS ***/
   tell_object(previous_object(), "You chant, 'xlxyx de gadrum'.\n");
   
    /*** TELL TARGET WHAT CASTER CHANTS ***/
   tell_object(params[1], (string)previous_object()->query_cap_name() +
    " chants, 'xlxyx de gadrum'.\n");
   
    /*** TELL TARGET WHAT HAPPENS TO HIM AFTER SPELL GOES OFF ***/
   tell_object(params[1], (string)previous_object()->query_cap_name()+
      " hits you with a Lightning Bolt.\n");
   
    /*** TELL CASTER THE EFFECTS OF HIS SPELL AND WHO IT HIT ***/
   tell_object(previous_object(), "You cast "+SP_NAME+" at "+
    (string)params[1]->query_cap_name() + ".\n");
   
    /*** TELLS ROOM THE EFFECTS OF THE SPELL BUT NOT CASTER OR TARGET ***/
   say((string)previous_object()->query_cap_name()+
    " finishes a spell and "+params[1]->query_cap_name()+" is struck "
      "with a lightning bolt.\n",({params[1],previous_object()}) );
  }

   /*** FOR LOOP TO RANDOMLY GENERATE DAMAGE, NO_OF_DICE(D)SIZE_OF_DICE ***/
   /*** 1d4 = 1 to 4 damage, or 1d6 = 1-6 damage, 6d6 would be 6-36, etc ***/
  for ( i=1 ; i<=NO_OF_DICE ; i++)
    damage = damage + random(SIZE_OF_DICE)+1;

   /*** SENDS INFO TO SAVING THROW ROUTINE IN SPELLS.C, IF VICTIM MAKES ***/
   /*** SAVE, DAMAGE WILL BE HALF ***/

  if (DETECTED == 1)  /** if illusion was detected, reduce damage to **/
   {                 /** just 20% of normal **/
     damage = (damage*20)/100;
   }

  damage = params[1]->spell_saving_throw(params[1],damage,save_type);

   /*** SENDS INFO TO DAMAGE ROUTINE IN SPELLS.C TO DO DAMAGE TO TARGET ***/
  params[1]->spell_damage(params[1],damage,TYPE,caster);

   /*** STARTS COMBAT BETWEEN TARGET AND CASTER ***/
  params[1]->attack_by(previous_object());

   /*** GIVES EXP TO CASTER EQUAL TO THE VALUE RETURNED ***/
  return GP_COST;

}
