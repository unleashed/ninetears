/*  File upgrade by Grimbrand 2-11-96                                   */

#include "path.h"
inherit "obj/monster";
 
void init() { ::init(); }

void setup() {
   set_name("captive");
   add_alias("orc");
   add_alias("Captive");
   set_short("Orc Captive");
   set_long("   Before you stands a dumb, slobbering orc.  He has been in "
            "captivity for a long time now and he has been consumed by "
            "the evil that has been festering in his heart.  He would "
            "like nothing more than to smash in your skull."
            "\n\n");
   set_main_plural("Captives");
   set_gender(1);
   set_race("orc");
   set_guild("fighter");
   set_random_stats(10,15);
   set_aggressive(0);
   set_level(10);
   set_max_hp(44);
   set_wimpy(0);
   set_al(0);
   set_kill_xp(631);
   adjust_money(random(3), "silver");
   clone_object("/d/newbie/duergar/weapons/sword.c")->move(this_object());
   this_object()->init_equip();
 
  load_chat(30,({
     1, "' The duergar will need to do much more than this to break my spirit.",
     1, ":sneers at you with utter disgust.",
     1, "'You are hardly even a challenge for me.",
 
  }));
 
  load_a_chat(25, ({
     1, ":draws blood.",
     1, ":slobbers and drools at the chance to kill you.",
     1, ":spits at your feet.",
     1,"'I have not endured this prison to be killed by you.",
 
  }));
}
