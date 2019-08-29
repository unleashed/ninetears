//modified by Ljen okt -96
// Coded By Joram 16  of  August '96

inherit "/obj/monster";
#include "path.h"

void setup(){

   set_name("lonin the metre");
   set_short("Lonin The Metre");
   set_long("The cooker of the keep is one of the first half-elves of the "
            "realms.  He is in charge of the food and the refrigerator and "
           "food-store in the kitchen.\nDressed in an apron and wielding "
     "food-store in the kitchen.\nDressed inan apron and wielding "
            "a big cooking spoon, he is ready to cook, you better get out "
            "before he sees the way you are looking at his meat.\n");

   add_alias("lonin");
   add_alias("cooker");
   add_alias("metre");

   set_main_plural("Lonins The Metres");
   add_plural("lonins");
   add_plural("cookers");
   add_plural("metres");

   set_gender(1);
   set_level(3);
   set_max_hp(40);
   set_race("half elf");

   add_clone("/d/newbie/half-elf/items/apron.c", 1);
   add_clone("/d/newbie/half-elf/items/spoon.c", 1);


   load_chat(60,({
      1,"'hmmmmmm...... what a delicious smell this *ack* thing has",
        1,"@asks: Where did i leave those recipies.. ?",
      1,"@gives the lasts flavours to the desert",
      1,"'hey You !!!, Yes You !!!, What the are you doing in my kitchen ?",
   }));

   load_a_chat(70,({
      1,"@exclaims: See what you have done !! now the cocodrile eyes are burnt !!!!",
      1,"@moves around the kitchen tables and skins following you",
      1,"@'s eyes bright with a madness light",
   }));

}
   
