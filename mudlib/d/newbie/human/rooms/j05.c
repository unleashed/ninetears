#include "path.h"
inherit HAVMAND+"jungle.c";

void setup()
{
    
    set_long("\nIsle of Havmand : Jungle\n\n"
    "The trees seem to be closing in on you, but you can still fight your "
    "way through the tangle of trunks and vines. The way east, however, is "
    "totally blocked, and there is no way you could cut your way through. "
    "To the west you can see what looks like a more permanent track, but "
    "its difficult to see clearly from here. "
    "\n\n");
    add_item( ({"trunk","trunks"}),"The trunks are gnarled and twisted, "
    "and covered in lichen and moss. "
    "\n");
    add_item( ({"vine","vines"}),"Long and thin, they hang down from great "
    "heights, but seem to be firmly attached to whatever they are growing "
"from.  Though they maybe useful, these are too small to of any help.\n"
    "\n");
    add_item("track","Although you can't see it clearly from here, it appears "
    "to be a deliberately made dirt track for use by carts or wagons."
    "\n");
}
void init()
{
    add_exit("north",HAVMAND+"j04.c","path");
    add_exit("south",HAVMAND+"j06.c","path");
    add_exit("west",HAVMAND+"t02.c","path");

    ::init();
}


