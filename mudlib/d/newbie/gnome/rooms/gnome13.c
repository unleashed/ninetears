inherit "/std/outside";
#include "path.h"

void setup ()   {
set_short("Macedonia:  West Gate");
set_light(40);
set_long("Macedonia:  West Gate\n\n"
            "   You are standing out a small path which continues "
            "through the gate to your west.  You do not notice much "
"here to peak your interest except for the sounds of "
            "Woodland animals that come from the Whispering Woods.  "
            "Now you must decide if you want to remain inside the "
            "relative safety of the city, or adventure out into the "
            "wilderness.  "
            "\n\n");
add_exit("east",VALLEY +"gnome14","path");
add_exit("west",VALLEY +"gnome12","path");
add_clone(NPC+"guard.c",1);
}
