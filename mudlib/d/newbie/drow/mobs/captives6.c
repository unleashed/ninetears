 
#include "path.h"
inherit "/obj/monster";
 
void setup() {
   add_alias("captive");
   add_alias("Captive");
   add_alias("human");
   set_name("captive");
   set_short("Human Captive");
   set_long("   Intelligent green eyes peer at you amusedly from "
            "a face otherwise covered in a thick black beard. "
            "The human is clothed in drab clothes, and around his "
            "wrists are broken shackles that you recognize "
            "as a frequent accessory to the captives' outfits. "
            " Vitality still exudes from this prisoner, however, "
            "and you sense that the drow have yet to break his "
            "spirit.\n");
   set_main_plural("captives");
   set_gender(1);
   set_race("human");
   set_guild("wizard");
   set_random_stats(10, 10);
   adjust_str(4);
   adjust_con(1);
   adjust_dex(2);
   set_level(4);
   set_max_hp(20);
   set_al(random(-100));
    clone_object(ITEM+"shackles.c")->move(this_object());
   load_chat(25, ({
         1, ":laughs amusedly.",
         1, "'It's a bit drafty in here -- do you think you can order me a "
         "blanket?",
         1, "'My toes are right chilly -- be a good knave and fetch me "   
          "some slippers.",
          1, "'Your drow call this a prison? Bah!",
          1, "'I could escape, but the service and accomodations here "
             "are so lovely...",
          1, "'I love what the drow have done to this place.",
         1, "'The early dungeon look is so vogue these days!"
   }));
   load_a_chat(30, ({
           1,"'I hear drow corpses are in great demand these days.",
           1, "'Has no one taught you drow manners yet?",
           1, "'I would rather not dull my blade with this.",
           1, "'Until this attack, I would have recommended Banefall "
              "as a charming vacation spot.",
           1, "'You'll be far more fun to kill than the cave lizards.",
           1,"'You want a captive audience? I'm all yours."
}));
 
} /* setup() */
