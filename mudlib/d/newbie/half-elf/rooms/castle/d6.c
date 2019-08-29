//Modified by Ljen okt -96
//Coded by Joram on the 16th of September '96

inherit "/std/room";
#include "path.h"

void setup(){
   set_short("Castle Of The Green Sun: Bedroom");
   set_long("This room belongs to the old wizard of the castle.  In the past "
            "he was very famous and the most brilliant mind in the realms. "
            "All the things you can see here, comes from that time, even "
            "the red robe he is wearing.  The bed is made with red sheets, the "
            "walls are painted with red paint and even the doors are red. "
            "There is not much to say about the rest, but the floor is also "
            "red ..\n");

   add_item("bed", "Everything is so red here, How did you manage to" 
                   " find it in here?\n");
   add_item(({"sheet","sheets"}), "The silk sheets are very old and fragile. "
                                  "They are also very dusty."
                                  "And, they are of course: %^BOLD%^RED%^Red%^RESET%^\n");

   set_light(50);

   add_clone(NPC+"old_w",1);

   add_exit("east",    CAST+"e6.c",   "door");
}

    
