#include "path.h"
inherit ROOM+"baseroom";
#include "restock.c"
object bigvine;

void setup()  { my_setup();
set_short("Realm of the Lizard:  Musty Swamp");
set_light(60);
set_long("\nRealm of the Lizard:  Musty Swamp\n\n"
	 "     Although you have gotten deeper into the swamp, you see a "
	 "clearing up ahead. It's a good walk to get there but you can "
	 "still see the clearing from here. You still see "
	 "a lot of those vines. When you get to the clearing you "
	 "should probably take a rest. The trees are becoming more "
	 "frequent now. The path is becoming a little easier to follow "
	 "now. Maybe things are taking a turn for the "
	 "better. \n\n");
add_property("no_undead",1);
add_item("trail", "The trail is becoming easier to follow now. "
	 "It seems beaten down a little as if it has carried "
	 "some traffic lately. \n\n");
add_item("clearing", "You see a clearing up ahead a couple of "
	 "miles to the south. Perhaps it would be good there. "
	 "\n\n");
add_item("vine", "This is a Large looking vine, a lot "
	 "larger than the ones you have been seeing. \n\n");
add_exit("south",SWAMP +"lizard10","room");
add_exit("northwest",SWAMP +"lizard04","room");

}

void reset() {

if(!bigvine)
bigvine = clone_object(MONSTER +"bigvine.c");
bigvine->move(this_object());
}
void dest_me()
{
if(bigvine)
bigvine->dest_me();
::dest_me();
}
