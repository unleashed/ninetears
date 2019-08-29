//Modified by Ljen okt -96
// Coded By Joram 16 of August '96

inherit "/obj/monster";
#include "path.h"


void setup(){

   set_name("drow");
   set_short("Drow");
   set_long("One of the inhabitants of the darkness of the earth, better run "
    "and save your life before it can smell you.. \n");

   set_main_plural("Drows");
   add_plural("drows");

   set_gender(1+random(1));
   set_level(8);
   set_max_hp(80);
   set_race("drow");
   adjust_money(5, "gold");
   set_aggressive(3);

   add_clone("/baseobs/weapons/leather.c", 1);
   add_clone("/baseobs/weapons/shortsword.c", 1);  

   load_chat(60,({
      1,"'klagh newing ona l'ors ",
      1,"@asks: zreb`l acklo labeleis ?",
      1,"@stands looking into darkness, seems waiting for a new victim",
   }));

   load_a_chat(30,({
      1,"@yells: Blother'xs klasdorn anapse !!",
   }));

}
   
