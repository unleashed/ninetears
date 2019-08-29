
#include "/w/sojan/combat/unarmed_combat.h"
#include "path.h"
inherit "/obj/monster.c";
/* blood sucking vampire from hell */
void setup()
{
   add_property("undead",25+random(25));
   set_name("vampyre");
   set_short("pale young woman");
   add_alias("vampire");
   add_alias("vampyre");
   set_long("\n  A rather attractive woman stands here, she has "
   "hypnotic blue eyes and straight black hair. Her bright bright red "
   "lips stand out against her very pale skin. "
   "\nShe smiles as she sees you look at her. "
   "The longer you look at her the more desirable she seems, "
   "you look into those eyes and lose yourself.............."
   "\n\n\n"
   );
set_al(2000);
   set_race("undead");
   set_race_ob("/std/races/undead");
   add_alias("woman");
   add_alias("young woman");
   set_gender(2);
   set_level(30);
   set_random_stats(10,10);
   set_dex(20);
   set_str(20);
   set_aggressive(0);
  set_thac0(-50);
  adjust_tmp_damage_bon(10);
   adjust_money(30,"gold");
   load_chat(100,({
        1,":smiles seductively",
        1,":kisses you then licks her lips",
        1,":nibbles on your left ear and sighs",
        1,"'just what this place needs, fresh blood !",
        1,"'how about you and me do the wild thing ?",
      1,":admires your fine neck",
      1,":wanders over to you and whispers sweet nothings in your ear",
        1,":winks",
        1,"'do you have any idea how hard it is to get good help these days ?"
        }));
   load_a_chat(100, ({
        1, "'but we were getting on so well",
        1, "'all I wanted was a wee sip",
        1, ":licks her lips and laughs",
        1, ":kisses you passionately"
   }));
} /* setup() */

/* Hamlet was here!  Don't try this at home kids.  make_corpse() now */
/* returns the money the vampyre had on it.  NOT normally a good idea. */
object make_corpse() {
    object *corpse = all_inventory(this_object());
    corpse[0]->move(environment(this_object()));
    return corpse[0];
}

valid_attack() {
   if((int)environment(attacker)->query_light() > 50 )
   {
	tell_room(environment(attacker),"The light starts to destroy the vampyre!\n",
	({ }));
         /* Below used to be attacker->dest_me()  which yarped. */
       attacker->adjust_hp(-5000,attacker);
   }
   switch(random(4))
   {
      case 0:
      if(defender->query_str() > 4)
      {
	    defender->adjust_tmp_str(-1);
	    tell_object(defender,"Vampire bites you lovingly on the neck, "
	    "draining your blood, and with it your strength.\n");
      }
      case 1:
	    attacker->adjust_hp(20);
	    tell_object(defender,"Vampire drinks "+DN+"'s blood and "
	    "looks healthier.\n");
      default:
   }
      return([
      "punch"    : ({ AN+" grabs "+DN+" and bites "+DN+" on the neck.\n",
		      "You bite "+DN+"'s neck.\n",
                      AN+" bites your neck and sucks blood.\n" }),
      "kick"     : ({ AN+" goes for the neck but bites "+DN+" on the shoulder.\n",
                      "You attempt to bite "+DN+" on the neck but settle for a chunk of shoulder.\n",
                      AN+" misses your neck and bites you on the shoulder.\n" }),
      "knee"     : ({ AN+" holds you close "+DN+".\n",
                      "You hold "+DN+" closely.\n",
                      AN+" holds you closely.\n" }),
      "headbutt" : ({ AN+" claws "+DN+" and licks the blood from her hands.\n",
                      "You claw "+DN+" and lick the blood from your hands.\n",
                      AN+" claws you then licks the blood from her hands.\n" })
   ]);
}

