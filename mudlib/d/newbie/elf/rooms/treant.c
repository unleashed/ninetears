#include "path.h"
inherit "/std/outside";

void setup()
{
add_property("no_undead",1);
set_short("Realm of the Elf:  Faeyn's Glen");
set_long("\n   Realm of the Elf:  Faeyn's Glen\n\n"
	"     You have entered the glen of Faeyn the Treant.  For countless "
		"centuries, treants and elves have lived in harmony with "
		"each other and the forest.  Faeyn stays in close contact "
		"with the elven community to preserve the health of the "
		"woods.  Elves often come here for guidance and for help.\n");
set_light(100);
add_exit("south",ROOM+ "center","road");
set_zone("road");
add_clone(CHAR+"faeyn.c",1);
add_item(({"glen","forest","woods","trees"}), "This is perhaps "
		"the healthiest and most beautiful woodland you have ever "
		"seen.  Must be the treant's influence.\n");
}
