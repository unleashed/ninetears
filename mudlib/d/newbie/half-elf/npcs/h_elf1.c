//Modified by Ljen dec -96
// Coded By Joram 16 of August '96

inherit "/obj/monster";
#include "path.h"


void setup(){

   set_name("half elf");
   set_short("Half Elf");
   set_long("This is one of the inhabitants of this little town.  This one is "
            "probably going visiting, all those delicious cakes must be for "
            "someone.  The half elven of this litle town are governed by "
            "the Princess of the Keep.\n");

   add_alias("elf");

   set_main_plural("Half Elfs");
   add_plural("elfs");
   add_plural("half elfs");

   set_gender(1+random(1));
   set_level(1+random(3));
   set_max_hp(10+random(50));
   set_race("half elf");

   add_clone("/d/newbie/half-elf/items/shovel.c",1);
   add_clone("/d/newbie/half-elf/items/rdress.c",1);

   load_chat(60,({
      1,"@walks happily down the street",
      1,"'Good day to you! ",
   }));

   load_a_chat(30,({
      1,"'you want them, you really want them ? taste this one !!!",
      1,"@yells: Alarm Alarm" ,
   }));

}
   
