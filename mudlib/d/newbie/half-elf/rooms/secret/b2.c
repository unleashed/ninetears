//modified by Ljen okt -96
//Coded by Joram on the 16th of September '96

inherit "/std/room";
#include "path.h"

void setup(){
   set_light(40);
   set_short("Strange Passage Behind Mirror");
   set_long("A small passage carved in the deep rock.\n");

   add_exit("east",     SECRET+"c2.c",    "path");
   add_exit("south",    SECRET+"b3.c",    "path");
}

    
