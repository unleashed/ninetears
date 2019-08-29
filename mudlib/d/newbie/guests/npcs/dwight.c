
#include "/w/sojan/combat/unarmed_combat.h"
#include "path.h"
inherit "/obj/monster.c";
/* wight */

void setup()
{
   add_property("undead",25+random(25));
   set_name("wight");
   set_short("wight");
   set_long("\n  A humanoid shape which is cloaked with a necrotic "
   "miasma, you can't really see it, but you can hear it moaning as "
   "it seeks your life forces. The sight of it fills you with "
   "terror, and you can only hope that your courage holds as you battle "
   "this manifestation of utter evil. "
   "It smells real bad too. "
   "\n\n"
   );
   set_level(40);
   set_race_ob("/std/races/undead");
   set_race("undead");
   set_al(1000);
   adjust_deity_status(400,"taniwha");
   adjust_ethics(400);
   set_str(20);
   set_gender(0);
   set_thac0(200);
   adjust_money(10,"platinum");
   load_a_chat(100, ({
	1, "'ssssssssssssssssaaaaaahhhhh!",
	1, ":snarls.",
	1, ":folds into itself for a moment, before resuming the attack.",
	1, ":writhes into obscene shapes for a moment to distract you."
   }));
} /* setup() */
void hit_stats()
{
   switch(random(6))
   {
   case 0:
      if(defender->query_str() > 2) defender->adjust_temp_str(-2);
   break;
   case 1:
      if(defender->query_con() > 5) defender->adjust_temp_con(-1);
   break;
   case 2:
	 if(defender->query_dex() > 5) defender->adjust_temp_dex(-2);
   break;
   case 3:
      if(defender->query_chr() > 2) defender->adjust_temp_chr(-2);
   break;
   case 4:
      if(defender->query_int() > 2) defender->adjust_temp_int(-2);
   break;
   case 5:
      if(defender->query_wis() > 2) defender->adjust_temp_wis(-2);
   break;
   }
   tell_object(defender,"The wight touches you and drains you.\n");
}
valid_attack() {
   int fear;
   if(environment(attacker)->query_light() > 80 )
   {
	attacker->set_wimpy(99);
	tell_room(environment(attacker),"The Wight is frightened by the "
   "light here, and attempts to flee into the dark.\n",({ }));
   }
   else attacker->set_wimpy(0);
   
   // Radix was here for Timion's fear attack resistances
   // December 2, 1995
   fear = defender->query_property("fear");
   if(fear>0)
   {
      if(random(100) < fear)
      {
         fear = 1;
         tell_room(environment(),defender->query_short()+" resists "
            "the Wight's fear attack!\n",defender);
         tell_object(defender,"You resist the Wight's fear!\n");
      }
      else fear = 0;
   }
   if(!fear)
   switch(random(10))
   {
      case 0:
	    defender->adjust_gp(-5);
	    defender->set_heartbeat(0);
	    tell_object(defender,"The wight paralyzes you with fear.\n");
      case 1:
	   hit_stats();
      case 2:
      case 3:
      case 4:
	   defender->set_wimpy(99);
	   tell_object(defender,"Fear roils up from your bowels and you want to flee.\n");
      break;
      default:
      break;
      }
      return([
      "punch"    : ({ AN+" tears at "+DN+"'s soul.\n",
		      "You tear at "+DN+"'s soul.\n",
		      AN+" tears at your soul.\n" }),
      "kick"     : ({ AN+" blasts "+DN+" with a wave of fear.\n",
		      "Blasts "+DN+" with a wave of fear.\n",
		      AN+" blasts you with fear.\n" }),
      "knee"     : ({ AN+" touches "+DN+".\n",
		      "You touch "+DN+".\n",
		      AN+" touches you.\n" }),
      "headbutt" : ({ AN+" engulfs "+DN+".\n",
		      "You engulf "+DN+".\n",
		      AN+" engulfs you.\n" })
   ]);
} /* valid_attack */


