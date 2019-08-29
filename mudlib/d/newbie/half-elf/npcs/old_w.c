//modified by Ljen okt -96
// Coded By Joram 16  of  August '96

inherit "/obj/monster";
#include "path.h"


void setup(){

   set_name("helsah the red");
   set_short("Helsah The %^BOLD%^RED%^Red%^RESET%^");
   set_long("This is the old wizard of the keep, althoug he is very old "
            "the power of his spells is still very high and the aura of "
            "might that surrounds him makes you feel lucky for having the "
            "opportunity to know someone like him.\nHelsah is dressed only with"
            " a red cape and hold a big golden staff in his right hand, which "
            "is used both as a stick and a magical item.\n");

   add_alias("helsah");
   add_alias("wizard");
   add_alias("old wizard");

   set_main_plural("Helsahs The %^BOLD%^RED%^Reds%^RESET%^");
   add_plural("helsahs");
   add_plural("wizards");
   add_plural("old wizards");

   set_gender(1);
   set_level(3);
   set_max_hp(40);
   set_race("elf");
   set_guild("wizard");

   add_clone("/d/newbie/half-elf/items/rrobe.c", 1);
   add_clone("/d/newbie/half-elf/items/goldstaff.c", 1);
   
   load_chat(60,({
      1,"'Nice day indeed, I better go out and have a walk around",
      1,"'I do not remember where I have left my earring.... hmmmm",
      1,"@scratches his head",
      1,"@walks around.... he seems worried about something",
      1,"'I wonder if that magic mirror still is.... errrrr what was I going to say ?",
   }));

   load_a_chat(70,({
      1,"@exclaims: You will pay for this with your DeAtH !!!!............ or was it life ?",
      1,"@starts to make some magical gestures and ..... BLAM !, nothing happends",
      1,"'I'll send you back to the eternal hole !!!",
   }));

}
   
