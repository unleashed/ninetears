 
#include "path.h"
inherit "/obj/monster";
 
void setup() {
   add_alias("captive");
   add_alias("dwarf");
   set_name("captive");
   set_short("Dwarf Captive");
   set_long("   A squat dwarven female glares at you. The "
            "rags that once were her clothes are full of filth and "
            "stench. Although the chains still attached to her "
            "ankles attest that she is a prisoner of the drow, "
            "she looks at you with pride and pure disdain.\n");
   set_main_plural("captives");
   set_gender(2);
   set_race("dwarf");
   set_guild("fighter");
   set_random_stats(5, 12);
   adjust_con(1);
   adjust_dex(5);
   adjust_money(random(5),"silver");
   set_level(4);
   set_max_hp(20);
   set_wimpy(0);
   //set_kill_xp(400);
  set_align(-500);
   set_ethics(-1000);
     clone_object(OBJ+"short_sword.c")->move(this_object());
  this_object()->init_equip();
    clone_object(ITEM+"shackles.c")->move(this_object());
 
   add_language("dwarf");
   do_command("speak dwarf");
   load_chat(200, ({
         1, ":sneers at you with hatred.",
      1, "'Have you no sense of decency?",
      1, ":looks you up, then, down, and then laughs uncontrollably.",
      1, ":smirks at you with only a glimmer of fear in her eyes.",
      1, ":gets a faraway look in her eyes.",
      1, "'You drow are good for nothing but ...well, nothing."
   }));
   load_a_chat(300, ({
           1, "'Oh, you big mean drow, able to fight half-dead "
           "prisoners!",
           1, "'I could beat you still chained to the wall!",
           1, ":puts her thumb on her nose and razzes you.",
           1, "'Ha! Are you sure you're using your weapons correctly, "
           "child?",
           1, ":laughs manically.",
           1,"'I've seen rocks that move faster than you!"
   }));    
   } /* setup() */
 
                                                 

