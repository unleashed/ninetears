// modified by Ljen okt -96
// Coded By Joram 16 of August '96

inherit "/obj/monster";
#include "path.h"


void setup(){

   set_name("half elf");
   set_short("Half Elf");
   set_long("This is one of the inhabitants of this little town.  This one is "
            "probably going to work in the orchard. The half elven of this "
            "little town are governed by the Princess of the Keep.\n");

   add_alias("elf");

   set_main_plural("Half Elfs");
   add_plural("elfs");
   add_plural("half elfs");

   set_gender(1+random(1));
   set_level(1+random(3));
   set_max_hp(10+random(30));
   set_race("half elf");


   add_clone("/baseobs/misc/torch.c", 1);
   add_clone("/d/newbie/half-elf/items/shovel.c", 1);

   load_chat(60,({
      1,"@sings a happy tune",
      1,"@whistles a happy tune",
      1,"@walks fastly, must be in a  hurry",
      1,"'Need any help ?, Wanna me to teach you how to manage with that weapon ?",
   }));

   load_a_chat(30,({
      1,"@exclaims: My shovel will get you !!!",
      1,"@yells: Alarm Alarm" ,
   }));

}
   
