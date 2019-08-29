#include "path.h"
inherit CASTLE+"baseroom.c";

void setup() { my_setup();
set_short("Realm of the Orc:  Room of Corpses");
set_light(40);
set_long("\n   Realm of the Orc:  Room of Corpses.\n\n"
         "     You notice that you are standing on corpses.  The corpses "
"are scattered thoughout the room. But there is something odd "
"about the bodies. There is only one noticeable exit to the south. "
"And since you can't go back up, you guess south is a good way to go! "
"Oddly enough, the exit is a large metal door.\n\n");
add_item(({"body","bodies","corpse","corpses","dead"}),"\n"
"  There are five or so corpses scattered on the floor of the room. "
"You notice no wounds on their bodies. It appears they all "
"might have starved to death.\n");
add_item("door", "\n\n"
"  The metal door is huge. There is no apparent rust on the door so it "
"seems very strong. There is no noticeable locking system on "
"the door so one can't assume the door was used to keep "
"things in or out.\n");
add_item(({"up","ceiling","shaft"}),"\n"
"  The ceiling is not impressively, but the shaft you fell though "
"makes you thank the gods that you are still alive.\n");
add_exit("south",DUNGEON +"dungeon2a","door");
}
