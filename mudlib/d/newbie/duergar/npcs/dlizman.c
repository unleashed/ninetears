/*  File upgrade by Grimbrand 2-11-96                                   */

#include "path.h"
inherit "obj/monster";
 
void init() { ::init(); }

void setup() {
   set_name("captive");
   add_alias("lizard-man");
   add_alias("Captive");
   add_alias("lizardman");
   set_short("Lizard-man Captive");
   set_long("   Before you stands a lizard-man.  He has managed "
            "to thrive on the bitter contempt that has been burning "
            "in his heart since his enslavement and captivity began.  "
            "He flicks his long tail and hisses at you almost daring "
            "you to attack him so that he may exact his vengence."
            "\n\n");
   set_main_plural("Captives");
   set_gender(1);
   set_race("lizard-man");
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
     1, "' Let me go you sssssslime.",
     1, "'The duergar will have to do much more than thisssssss to break my ssssssssspirit.",
 
  }));
 
  load_a_chat(25, ({
     1, ":smashes you with his tail.",
     1, "Aaah, ssssssso you've come to fight the weak and oppresssssssed.  Ssssssssssoooo noble.",
     1, ":spits at your feet.",
     1, "'I have not endured thissssss prissssssson to be killed by you.",
 
  }));
}
