#include "path.h"
inherit "/std/room";

void setup()
{
    set_short("Bedroom.");

    set_long("     This is where all the commoners and servants sleep.  "
	"It is a rather crude and plain looking room.  Since "
	"there is no space for beds, everybody is forced to sleep "
	"on the floor.  The bedrolls are all piled in a corner "
	"of the room.  The walls have some writings spread all "
	"through them.\n\n");

   add_item("walls", "Looking at the walls, you can read writings "
	"like: PRAISE CYRCIA, KILL THEM ELVES and CHAOS IS OUR "
	"WAY.\n\n");
   set_light(20);
  add_clone(PATH+"child", 1);
   add_exit("west", PATH+"drow.c");
}
