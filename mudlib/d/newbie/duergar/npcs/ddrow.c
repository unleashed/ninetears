/*  File upgraded by Grimbrand 2-11-96                                  */

#include "path.h"
inherit "obj/monster";
 
void init() { ::init(); }

void setup() {
   set_name("captive");
   add_alias("drow");
   add_alias("Captive");
   add_alias("leader");
   set_short("Drow Captive");
   set_long("   Before you stands a houseless Drow female.  That has been "
            "captured.  Due to the fact that she is houseless, indicates "
            "she isn't a very powerful drow.  Had she been born a "
            "noble, she would have trained to be a priestess of "
            "Lolth, making her a very dangerious adversary."
            "\n\n");
  set_main_plural("Captives");
  set_gender(2);
  set_race("drow");
  set_guild("fighter");
  set_random_stats(10,15);
  set_aggressive(0);
  set_level(10);
  set_max_hp(44);
  set_wimpy(0);
  set_al(0);
  set_kill_xp(631);
adjust_money(4+random(4),"silver");
  clone_object("/d/newbie/duergar/weapons/sword.c")->move(this_object());
  this_object()->init_equip();
 
add_language("drow");
do_command("speak drow");
  load_chat(30,({
  1, "' The duergar will need to do much more than this to break my spirit.",
 
  }));
 
  load_a_chat(25, ({
     1, ":calls upon her god Lolth to bring forth the flames of hell upon you.",
     1, ":gracefully dodges your clumsy attacks.",
     1, "'Aaah, so you've come to fight the weak and oppressed.  So noble.",
     1,":taunts you, confident in her strength.",
 
  }));
}
