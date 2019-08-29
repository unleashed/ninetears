/*  File upgrade by Grimbrand 2-11-96                                   */

#include "path.h"
inherit "obj/monster";
 
void init() { ::init(); }

void setup() {
   set_name("captive");
   add_alias("goblin");
   add_alias("Captive");
   set_short("Goblin Captive");
   set_long("   Before you stands a hideous goblin.  He reeks from "
            "uncleanliness and flashs a hideous smile at you.  "  
            "\n\n");
   set_main_plural("Captives");
   set_gender(1);
   set_race("goblin");
   set_guild("fighter");
   set_random_stats(10,15);
   set_aggressive(0);
   set_level(10);
   set_max_hp(44);
   set_wimpy(0);
   set_al(0);
   set_kill_xp(631);
   adjust_money(2,"gold");
   clone_object("/baseobs/weapons/dagger.c")->move(this_object());
   this_object()->init_equip();
 
  load_chat(30,({
     1, ":flashes his spiked teeth.",
     1, "' The duergar will have to do much more than this to break my spirit.",
     1, ":sneers at you with utter disgust.",
 
  }));
 
  load_a_chat(25, ({
     1, ":hisses at you.",
     1, ":draws blood.",
     1,"'I have not endured this prison to be killed by you.",
 
  }));
}
