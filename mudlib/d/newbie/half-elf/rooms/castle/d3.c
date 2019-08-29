//Modified by Ljen okt -96
//Coded by Joram on the 16th of September '96

inherit "/std/room";
#include "path.h"

void setup(){
   set_short("Castle Of The Green Sun: Bed room");
   set_long("The room of the princess is the largest and the most "
            "decorated in the castle.  The bed, at the north wall, is big "
            "with four legs of two meters hight and is dressed with red and "
            "pink sheets.  At the east wall there is a small window and a " 
            "little table just under it, where there are lots of "
            "perfumes.  At the south wall the chimney gives warm and light to "
            "the whole room and just above it there is a bronce mirror.\n");

   add_item("chimney", "Carved in the rock.\n");

   add_item("bed", "A large bed, with huge pillows scattered around.\n");
   
   add_item("mirror","A bronce mirror, used by the princess when she brush her hair.\n");
   
   add_item("window", "A small window, still it has a splendid view over"
	    " the nearby forest. Must be nice to just sit here and let"
	    " your mind rest. \n");
  
   add_item("table", "A litte table made of a kind of red wood, with"
	    " a faint glow in it. It is probably the most beautiful"	
            " wood you have ever seen.\n");
  
   set_light(50);

   add_clone(NPC+"princes",1);

   add_exit("east", CAST+"e3.c", "door");
}

    
