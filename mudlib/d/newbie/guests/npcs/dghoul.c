
#include "/w/sojan/combat/unarmed_combat.h"
#include "path.h"
inherit "/obj/monster.c";
/* ghoul */

void init() { ::init(); }

void setup()
{
   add_property("undead",25+random(25));
   set_name("ghoul");
   set_short("ghoul");
   set_long("\n A plump man with dark brown skin with an unpleasant "
   "greenish cast to skin smiles showing more sharp white teeth than "
   "anything remotely human should have. He is covered in scraps of "
   "uncured hide, and even standing upwind, the smell almost knocks you "
   "down. He is absolutely hairless, and his eyes seem to have almost "
   "no pupils. "
   "Long finger nails are filthy and seem to have scraps of flesh "
   "dangling from them. "
   "The aura of evil he exudes almost exceeds his body odor."
   "\n\n"
   );
   set_race_ob("/std/races/undead");
   set_race("undead");
   adjust_ethics(300);
   adjust_deity_status(300,"taniwha");
   set_thac0(160);
   set_al(3000);
   set_level(30);
   set_random_stats(10,10);
   set_str(20);
   set_gender(1);
   adjust_money(50,"silver");
   add_property("undead",1);
   load_chat(100, ({
      1,"'eat up, you look rather thin",
      1,":eyes you speculatively",
      1,"'What'll it be , freshest meat patties in the realms ?",
      1,"'I can recommend the Bloody Mary, the ingredients are real fresh",
      1,":grins like a duck with a flexible beak at you",
      1,"'Ignore the vampyre, her bites worse than her bark"
   }) );
   load_a_chat(100, ({
        1, "'Fresh meat, YEEHAA!",
        1, ":drives his claws into your chest",
        1, "'how about just one leg ?, then you can hop off",
        1, "'hang you for a week, to age, yummy "
   }));
} /* setup() */

mapping valid_attack()
{

/*
   switch(random(6))
   {
      case 0:
         if(defender->query_con() > 5)
            defender->adjust_tmp_con(-1);
   tell_object(defender,"Ghoul drains you.\n");
      default:
      break;
   }
   */
      return([
      "punch"    : ({ AN+" grasps hungrilly at "+DN+"\n",
                      "You grasp "+DN+".\n",
                      AN+" grasps you and you feel ill.\n" }),
      "kick"     : ({ AN+" bites "+DN+" ankle.\n",
                      "Bites "+DN+" on the ankle.\n",
                      AN+" bites your ankle.\n" }),
      "knee"     : ({ AN+" tears flesh from "+DN+" and gobbles it down.\n",
                      "You tear flesh from "+DN+" and eat it.\n",
                      AN+" tears flesh from your body and eats it.\n" }),
      "headbutt" : ({ AN+" slashes "+DN+" with his filthy claws.\n",
                      "You slash "+DN+" with your claws.\n",
                      AN+" slashes you with its claws.\n" })
   ]);
 }
   

