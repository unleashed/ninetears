inherit "/std/outside";
#include "path.h"

void setup ()   {
set_short("Macedonia:  Town Square");
set_light(40);
set_long("Macedonia:  Town Square\n\n"
            "   Town square is located directly in the center of "
            "the village of Macedonia.  From here there is a "
            "narrow path that leads east and west in between "
            "two rows of buildings.  These rows of buildings, "
            "which are to the north and south, appear to form "
            "a circle, with enough of a segment removed to allow "
           "traffic to flow along the path.  Built in the center "
           "of town, there is a large sculpture of a gnomish "
           "adventurer.  This sculpture adds a perfect touch to "
           "the beauty of the village. "
      "You see a temple to the northwest."
           "\n\n");
add_exit("south",VALLEY+"tavern.c","path");
add_exit("north",VALLEY+"smithy.c","path");
add_exit("east",VALLEY +"gnome15","path");
add_exit("west",VALLEY +"gnome13","path");
add_exit("southwest",VALLEY+"shop.c","path");
add_exit("northwest", VALLEY+"raiseroom.c","path");
add_exit("northeast",VALLEY+"hall.c","path");
add_exit("southeast",VALLEY+"guildroom.c","path");
add_clone(MISC+"statue.c",1);
add_clone(NPC+"makayla.c",1);
}
