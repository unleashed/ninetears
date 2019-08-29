/*  File upgrade by Grimbrand 2-11-96                                   */

#include "path.h"
inherit "obj/monster";
 
void init() { ::init(); }

void setup() {
   set_name("elf");
   add_alias("Captive");
   set_short("elf captive");
   set_long("   Before you stands a young elven female.  Her "
            "delicate features are marred as she stares at you with "
            "obvious hate.  She almost appears to be too small to wield "
            "the two swords that she carries.  The burning desire "
            "that you see spark deadly in her eyes tell you otherwise."
            "\n\n");
   set_main_plural("Captives");
   set_gender(2);
   set_race("elf");
   set_guild("fighter");
   set_random_stats(10,15);
   set_aggressive(0);
   set_level(10);
   set_max_hp(44);
   set_wimpy(0);
   set_al(0);
   set_kill_xp(631);
   adjust_money(3,"gold");
   clone_object("/d/newbie/duergar/weapons/sword.c")->move(this_object());
   this_object()->init_equip();
 
  add_language("elf");
  do_command("speak elf");
  load_chat(30,({
     1, "' The duergar will need to do much more than this to break my spirit.",
     1, "'Your people shan't be safe here for long.",
     1, "'You are hardly even a challenge for me.",
 
  }));
 
  load_a_chat(25, ({
     1, ":points at you, and then at the exit.",
     1, ":gracefully dodges your clumsy attacks.",
     1, "'Aaah, so you've come to fight the weak and oppressed.  So noble.",
     1,":taunts you, confident in her strength.",
     1,"'I have not endured this prison to be killed by you.",
 
  }));
}
