//Ljen dec -96
//Coded by Yalaba on the 29th of August of '96

inherit "/std/outside";
#include "path.h"
               
void setup(){
   set_light(80);
   set_short("Jungle Town: orchard");
   set_long("Here is the town orchard, in here you "
            "can see some half-elven working on the trees caring for them "
            "and collecting a strange big red fruit, which seems much more "
            "a branch of the tree itself than what it really is.  It seems "
            "this orchard is the one which provides all the town vegetables "
            ",as far as you can see there are no more things here except the "
            "trees. Those fruits could be very rich and "
            "nutritious.\nFruit Tree is here\n");

   add_item(({"tree","fruit tree"}), "This big tree reminds you of the "
                                     "apple tree, but a bit bigger.  It's "
                                     "branches are full of a small red fruit.\n"); 
   add_clone(NPC+"h_elf1.c",1);
   add_clone(NPC+"h_elf.c",1);

   add_exit("north", TOWN+"b1.c"   , "path");
   

}


