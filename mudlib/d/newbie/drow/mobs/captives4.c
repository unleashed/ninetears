 
#include "path.h"
inherit "/obj/monster";
 
void setup() {
   add_alias("captive");
   add_alias("Captive");
   add_alias("elf");
   set_name("captive");
   set_short("Elf Captive");
   set_long("   Pointed ears poke through disheveled hair as the elf "
             "returns your stare proudly.  Dark dirt covers his "
             "face and skin, and one might almost mistake him for "
             "a drow from a distance.  The proud look in his eyes and "
             "countenance, however, assure you that he considers himself "
             "high above the drow and that his spirit has not been broken "
             "yet.\n");
   set_main_plural("captives");
   set_gender(1);
   set_race("elf");
   set_guild("cleric");
   set_random_stats(5, 10);
   adjust_dex(5);
set_level(4);
   set_max_hp(20);
  set_align(-500);
   set_ethics(-500);
     clone_object(OBJ+"dagger.c")->move(this_object());
  this_object()->init_equip();
    clone_object(ITEM+"shackles.c")->move(this_object());
 
   add_language("elf");
   do_command("speak elf");
   load_chat(25, ({
         1, ":self-consciously adjusts his rags.",
         1, "'The drow have no right to keep me here!",
      1, ":counts the months he has spent here on his fingers and toes.",
      1, "'I am of no use to you or your people.",
      1, "'Who does your decorating? Lizard-men?",
      1, "'My god Tempus has abandoned me!",
   }));
   load_a_chat(30, ({
           1,"'Am I kept here to be a mere pawn for your sport?",
           1, "'Pick on someone your own size!",
           1, ":kicks dust at your feet.",
           1, "'You waste your energy, young friend.",
           1, ":doesn't consider you much of a threat.", 
           1, "'You demon! Demons, all of you!",
           1, "'Aah, you'll soon see that my sword is as sharp as my tongue."
 
           }));
 
} /* setup() */
