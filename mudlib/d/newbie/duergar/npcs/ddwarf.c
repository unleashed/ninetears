/*  File upgrade by Grimbrand 2-11-96                                   */

#include "path.h"
inherit "obj/monster";
 
void init() { ::init(); }

void setup() {
   set_name("dwarf");
   add_alias("Captive");
   set_short("Dwarf Captive");
   set_long("   This is a stout looking male dwarf.  As most dwarves "
            "are, he appears to be strong and tough.  He looks at you "
            "with utter contempt and hatred."
            "\n\n");
   set_main_plural("Captives");
   set_gender(1);
   set_race("dwarf");
   set_guild("fighter");
   set_random_stats(10,15);
   set_aggressive(0);
   set_level(10);
   set_max_hp(44);
   set_wimpy(0);
   set_al(0);
   set_kill_xp(631);
   adjust_money(random(10), "silver");
   clone_object("/d/newbie/duergar/weapons/sword.c")->move_(this_object());
   this_object()->init_equip();
 
  add_language("dwarf");
  do_command("speak dwarf");
  load_chat(30,({
     1, "' The duergar will need to do much more than this to break my spirit.",
     1, ":sneers at you with utter disgust.",
     1, "'You are hardly even a challenge for me.",
 
  }));
 
  load_a_chat(25, ({
     1, ":vows to make you suffer.",
     1, "'Aaah, so you've come to fight the weak and oppressed.  So noble.",
     1, ":spits at your feet.",
     1,"'I have not endured this prison to be killed by you.",
 
  }));
}
