//Ljen nov -96
//Coded by Yalaba on the 11th of September of '96

inherit "/std/outside";
#include "path.h"

void setup(){
   set_light(80);
   set_short("Jungle Town");
   set_long("To your north you can see what could look like a shop."
	    " The town seems quiet, almost noone out in the streets."
	    " It is peaceful here, small birds singing in the trees, and"
	    " flying around your head.\n");
  
   add_clone(NPC+"bird.c", 1);

   add_exit("east", TOWN+"c4", "path");
   add_exit("west" , TOWN+"a4"   , "path");
   add_exit("north", TOWN+"b3"  , "path");
}

