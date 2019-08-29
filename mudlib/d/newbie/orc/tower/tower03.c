#include "path.h"
inherit CASTLE+"baseroom.c";

void setup ()   { my_setup();
set_short("Realm of the Orc:  First Landing");
set_light(40);
   set_long("\n   Realm of the Orc:  First Landing.\n\n"
            "     This is a part of a landing on the staircase that looks "
            "as if a major part of the battle occured here.  The walls "
            "are splattered with blood and large chunks of the stone "
            "have been removed by the weapons used here.  The landing "
            "continues to the southeast while the staircase leads "
            "upward along the curved wall.  "
            "\n\n");

add_item(({"blood","battle","walls","wall","stone"}), "\n"
"  The battle must have been savage. The walls are scared with "
"stray blows of weapons that missed their marks. "
"The smell of death still lingers in the musty air.\n");

add_exit("up",TOWER +"tower04","room");
add_exit("southeast",TOWER +"tower02","room");
}
