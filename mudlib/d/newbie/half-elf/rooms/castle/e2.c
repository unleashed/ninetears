//Modified by Ljen okt -96
//Coded by Joram on the 12th of September '96

inherit "/std/room";
#include "path.h"

void setup(){
   set_short("Castle Of The Green Sun: Corridor");
   set_long("You are standing at the corridor of the castle's first floor,"
            "which leads to the chambers of the inhabitants of this castle. "
            "The walls and ceiling are nude but the torches.  On the floor 
there "
            "is a carpet all along with some strange drawings in it.\n");

   add_item("torch", "A common torch with a wooden haft and a cloth head "
                     "swet in oil\n");

   add_item("drawings", " The drawings seems to be a very old language where"
	    " you can understand some words: "
	    " '.... Mirror ..exit.... treasure....  pull.'\n");

   add_item("carpet", "A red carpet with golden drawings.  The drawings" 
	    " seems to be a very old language where you can understand"
 	    " some words: '.... Mirror ..exit.... treasure....  pull.'\n");

   set_light(50);
        
   add_exit("west",      CAST+"d2.c",  "door" );
   add_exit("north",     CAST+"e1.c",  "path" );
   add_exit("south",     CAST+"e3.c",  "path" );
   
}

    
