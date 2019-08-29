/*  File upgrade by Grimbrand 2-11-96                                   */

#include "path.h"
inherit "obj/monster";
 
void init() { ::init(); }

void setup() {
   set_name("captive");
   add_alias("half-orc");
   add_alias("Captive");
   set_short("Half-Orc Captive");
   set_long("   This is a half-orc.  He has the face of an ugly orc, the "
            "body of a human, and twenty times the resolve you do.  He has "
            "been in captivity for too long now and would like nothing "
            "more than to cause you extreme pain."
            "\n\n");
   set_main_plural("Captives");
   set_race("half-orc");
   set_gender(1);
   set_guild("fighter");
   set_random_stats(10,15);
   set_aggressive(0);
   set_level(10);
   set_max_hp(44);
   set_wimpy(0);
   set_al(0);
   set_kill_xp(631);
   adjust_money(9,"silver");
   clone_object("/d/newbie/duergar/weapons/sword.c")->move(this_object());
   this_object()->init_equip();
 
  load_chat(30,({
     1, "' The duergar will need to do much more than this to break my spirit.",
     1, ":sneers at you with utter disgust.",
 
  }));
 
  load_a_chat(25, ({
     1, ":slobbers and drools at the idea of killing you.",
     1, ":deftly thwarts your attack.",
     1,"'I have not endured this prison to be killed by you.",
 
  }));
}
