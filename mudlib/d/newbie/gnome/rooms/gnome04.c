inherit "/std/outside";
#include "path.h"

void setup ()   {
set_short("Macedonia:  Shadow Valley");
set_light(40);
   set_long("Macedonia:  Shadow Valley\n\n"
            "   From the wild growth of trees and brush, you "
            "assume that you are standing in one of the "
            "deepest parts of the forest.  From here, you "
            "notice a narrow path leading through the brush "
            "to the west.  Much to your enjoyment, you can "
            "hear the sounds of many different forest "
            "animals.  "
            "\n\n");
add_item("trees","Ths trees here have grown to enormous heights.  "
         "Their growth has caused the forest to be cover with a "
         "refreshing shade.\n");
add_item(({"brush","dense brush"}),"This brush is just the average "
           "wild shrubs found in most forest areas.  Since the "
           "light here is so scarce, the are no blooms growing "
           "here.\n");
add_item(({"forest","woods"}),"From here, you can see the edge of "
           "the forest.  Due to its density, you can not see far "
           "into it.\n");
add_clone(NPC+"snake.c",3);
add_clone(NPC+"frog.c",2);
add_exit("north",VALLEY +"gnome02","path");
add_exit("west",VALLEY +"gnome03","path");
add_property("no_undead", 1);
}
