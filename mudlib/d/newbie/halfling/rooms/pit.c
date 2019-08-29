#include "path.h"
inherit "/std/outside";

void setup()
{
add_property("no_undead",1);
set_light(LIGHT);
set_short("Island of Maroek:  Entrance to the Pit.");
 set_long("Island of Maroek:  Entrance to the Pit\n\n"
"This is the dreaded entrance to the Pit.  Sand is swept all along the sides, and "
"there is not a sound around you other than your own heart beat.  There doesn't "
"appear to be any vegetation in the entire area, and you cannot help but wonder why."
"\n\n");
add_item("sand","The sand here funnels downward.  If you wade into the sand, you "
"probably could drift down with it.\n");

add_exit("down",ROOMS+"pit2.c","path");
add_exit("south",ROOMS+"half25.c","path");
}


