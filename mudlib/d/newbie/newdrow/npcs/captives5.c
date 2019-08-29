 
#include "path.h"
inherit "/obj/monster";
 
void setup() {
   add_alias("captive");
   add_alias("Captive");
   add_alias("human");
   set_name("captive");
   set_short("Human Captive");
   set_long("   A tall, once-muscular human stands before you.  Strong hands "
            "that are unable to stop shaking cross in front of him, "
            "and you notice a gold ring that marks him as one of the "
            "nobles of the surface world.  Unfortunately, his title "
            "will bring him not fame or land but only more hardship "
            "at the hands of the drow.\n");
   set_main_plural("captives");
   set_gender(1);
   set_race("human");
   set_guild("cleric");
   set_random_stats(5, 10);
   adjust_con(1);
   adjust_dex(0);
   set_align(-350);
   set_level(4);
   set_max_hp(20);
   set_al(random(-100));
      clone_object(OBJ+"dagger.c")->move(this_object());
  this_object()->init_equip();
    clone_object(ITEM+"shackles.c")->move(this_object());
 
   load_chat(25, ({
         1, ":looks at you uneasily.",
         1, ":shudders from your presence.",
      1, ":daydreams of days spent on the surface at the Lady Luck Tavern.",
      1, "'Aaah..what I would give to see the sun again.",
      1, "'On the surface, that's where true beauty lies.",
      1, "'Once upon a time, I had a glorious tan.",
      1, ":smiles wistfully.",
      1, "'My family would pay quite handsomely for my release."
   }));
   load_a_chat(30, ({
           1, ":mutters curses at you under his breath.",
           1, "'In Daggerford, few would kill a weakened captive.",
           1, "'A spot of mercy! I will do you no harm!",
             1, "'My family will avenge me!",
           1, "'Please, take pity on me.",
           1, ":looks furtively for a way to escape."
 
   }));
 
} /* setup() */
