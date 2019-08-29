inherit "/std/outside";
#include "path.h"

void setup ()   {
set_short("Macedonia:  Shadow Valley");
set_light(40);
   set_long("Macedonia:  Shadow Valley\n\n"
            "   You are surrounded by dense plant life that has "
            "been growing in this area for several years now.  "
            "The only sign of recent activity is the narrow path "
            "that leads to both the west and south.  Sounds of "
            "animals coming from the west urge you to venture in "
            "that direction.  "
            "\n\n");
add_item(({"plants","plant life"}),"With the sunlight very dim "
           "here, these plants are a little scarce.  The few "
           "plants that grow here are rather green but have no "
           "blooms frowing on them.\n");
add_item("path","This path is a narrow dirt path made by the "
         "large amount of traveling through this forest.\n");
add_exit("south",VALLEY +"gnome17","path");
add_exit("west",VALLEY +"gnome10","path");
add_property("no_undead", 1);
add_clone(NPC+"bandit.c",3);
}
