 
#include "path.h"
inherit "/obj/monster";
 
void setup() {
   add_alias("captive");
   add_alias("Captive");
   add_alias("elf");
   set_name("captive");
   set_short("Elf Captive");
   set_long("   A slight elf with stooped shoulders stops his sobbing "
            "long enough to notice you.  His skin stretches tightly "
            "against his skin showing the outline of his gaunt face "
            "and his lack of food.  Clothes that once fit him hang "
            "loosely off his frame.\n");
   set_main_plural("captives");
   set_gender(1);
   set_race("elf");
   set_guild("cleric");
   set_random_stats(5, 10);
   set_level(4);
   set_max_hp(20);
   set_align(-1000);
   set_ethics(500);
   set_al(random(-100));
     clone_object(OBJ+"dagger.c")->move(this_object());
    clone_object(ARM+"leather.c")->move(this_object());
   do_command("equip");
    clone_object(ITEM+"shackles.c")->move(this_object());
 
   add_language("elf");
   do_command("speak elf");
   load_chat(25, ({
         1, ":snivels unattractively.",
         1, ":shows you a small portrait of his wife and four children.",
      1, "'Please save me! I could learn to become drow!",
      1, "'A crumb of bread or sip of water, I beg of you...",
      1, ":apologizes profusely for anything he's ever done to wrong you.",
      1, ":appeals to whatever kindness you might have.",
      1, ":sighs heavily.",
      1, ":clutches at your leg."
   }));
   load_a_chat(30, ({
           1, "'By the grace of Tymora, have you no heart?",
           1, ":sobs weakly.",
           1, ":hugs both your knees, tears streaming down his face.",
           1, "'Please refrain -- I am weak.",
           1, ":tries to persuade you to end your attack.",
           1, ":drops to one knee and begs for mercy."
   }));
 
} /* setup() */
 
           
