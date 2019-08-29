#include "path.h"
inherit CASTLE+"baseroom.c";
void setup()  { ::my_setup();
set_short("Realm of the Orc:  Tower Base");
set_light(40);

   set_long("\n   Realm of the Orc:  Tower Base.\n\n"
            "     This is a completely circular room with plain, empty "
            "walls.  Looking upward, you realize this is the tower "
            "itself.  A staircase, following the curvature of the "
            "wall leads upward into the darkness past the scars "
            "left here by the invaders.  There is a small doorway "
            "to the southeast.  "
            "\n\n");
   add_item(({"stairs","staircase"}),"  The staircase follows the "
       "curvature of the wall as it spirals upward into blackness.  "
       "It looks to be very sturdy and safe.  "
       "\n");
   add_item(({"wall","scars","blood"}),"  The walls are covered with "
       "dried blood that has flaked off in several places revealing "
       "several scars that were likely caused by a sword or "
       "axe.  \n");
   add_item("tower","  You can not tell much about the tower because "
       "you are inside it. \n");
add_exit("southeast",CASTLE +"orc02","door");
add_exit("up",TOWER +"tower01","door");
}

