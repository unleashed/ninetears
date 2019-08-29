/*  File upgrade by Grimbrand 2-11-96                                   */

#include "path.h"
inherit "obj/monster";
 
void init() { ::init(); }

void setup() {
   set_name("captive");
   add_alias("human");
   add_alias("Captive");
   set_short("Human captive");
   set_long("   This is a human male.  He has been beaten "
            "during his captivity and it shows in his weak "
            "looking stature.  His resolve is stronger than ever though "
            "and he is looking for some way to vent his anger and "
            "frustrations.  His glance seems to say that "
            "you are the perfect one to help do this."
            "\n\n");
   set_main_plural("Captives");
   set_gender(2);
   set_race("human");
   set_guild("fighter");
   set_random_stats(10,15);
   set_aggressive(0);
   set_level(10);
   set_max_hp(44);
   set_wimpy(0);
   set_al(0);
   set_kill_xp(631);
   adjust_money(1,"gold");
   clone_object("/d/newbie/duergar/weapons/sword.c")->move(this_object());
   this_object()->init_equip();
 
  load_chat(30,({
     1, "' I will have vengence.  You will die.",
     1, "' The duergar will need to do much more than this to break my spirit.",
 
  }));
 
  load_a_chat(25, ({
     1, "'Aaah, so you've come to fight the weak and oppressed.  So noble.",
     1, ":spits at your feet.",
     1,"'I have not endured this prison to be killed by you.",
 
  }));
}
