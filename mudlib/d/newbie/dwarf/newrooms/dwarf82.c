//  Dwarven Newbie Area:  Created By Mist   Fall 1994
//   Addition to the Dwarven Newbie Area:   Mist Spring 1997

#include "path.h"
inherit ROOM+"baseroom2.c";

object caverat;
void setup ()   { my_setup();
set_short("Realm of the Dwarf:  Large Room");
set_zone("CAVE");
set_light(40);

	set_long("\n   Realm of the Dwarf:  Large Room\n\n"
            "   Those who were tunneling out this cave must have found "
            "whatever they were looking for here.  The room is very "
            "large and there are dozens of holes carved into the walls "
            "on all sides.  The ceiling is far above your head, though "
            "you cannot imagine how anyone managed to do any diging "
            "up that high.  The marks left by the tools here do seem "
            "verify that this room was carved out by someone.  The only "
            "exit is back to the west.  "
		"\n\n");
add_exit("west",ROOM+"dwarf81","path");
}
