#include "path.h"
inherit CASTLE+"baseroom.c";

void setup ()   { my_setup();
set_short("Realm of the Orc:  First Landing");
set_light(40);
   set_long("\n   Realm of the Orc:  First Landing.\n\n"
            "     You are standing on the first landing of the tower.  "
            "The stairway here leads down along the wall while the "
            "landing goes to the northwest to another section of "
            "stairs leading up.  "
            "\n\n");
add_item(({"stairs","stairway"}),"You notice the stairs are well-worn by iron-shod feet.\n");
add_item(({"walls","wall"}),"The walls are covered with dried blood.\n");
add_item(({"blood","dried blood"}),"This is blood dried to a thick, dark paste of a black hue.  You imagine a "
	"very nasty battle took place here long ago.\n");
add_exit("northwest",TOWER +"tower03","room");
add_exit("down",TOWER +"tower01","room");
}
