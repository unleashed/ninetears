#include "path.h"
inherit "/std/outside.c";

void setup()
 {
    set_short("xxxx");

    set_long("\nElven treehouse.\n\n"
        "       \n\n");
 
    set_light(80);
   
    add_item("xxx","   \n");   
 
    add_smell(({"xxx","xxx"}),"    \n");
               
        
    add_exit("xxxx",ROOMS+"v1.c","path");	
         
   }