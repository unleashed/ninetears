/*  File upgrade by Grimbrand 2-11-96                                   */

#include "path.h"
inherit "obj/monster";
 
void init() { ::init(); }

void setup() {
   set_name("captive");
   add_alias("half-elf");
   set_short("Half-Elf Captive");
   set_long("   This is a half-elf.  He is thin and sickly looking from "
            "horrid treatment he has recieved while in captivity.  " 
            "He has vowed to return to his homeland someday and "
            "killing you seems like a good start."
            "\n\n");
   set_main_plural("Captives");
   set_gender(1);
   set_race("half-elf");
   set_guild("fighter");
   set_random_stats(10,15);
   set_aggressive(0);
   set_level(10);
   set_max_hp(44);
   set_wimpy(0);
   set_al(0);
   set_kill_xp(631);
   adjust_money(3,"gold");
   clone_object("/baseobs/weapons/dagger.c")->move(this_object());
   this_object()->init_equip();
 
  load_chat(30,({
     1, "' My god Timion will bring forth his wrath upon you all!",
     1, "' The duergar will need to do much more than this to break my spirit.",
     1, ":sneers at you with utter disgust.",
 
  }));
 
  load_a_chat(25, ({
     1, "'Aaah, so you've come to fight the weak and oppressed.  So noble.",
     1,"'I have not endured this prison to be killed by you.",
 
  }));
}
