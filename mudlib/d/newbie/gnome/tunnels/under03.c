inherit "/std/room";
#include "path.h"

void setup ()   {
add_property("no_undead",1);
set_short("Realm of the Gnome:  Macedonian Tunnel");
set_light(40);
set_long("\nRealm of the Gnome:  Macedonian Tunnel\n\n"
	 "     You have moved deeper into the tunnels, and as you glance back you "
    "notice that there is naught but a tiny speck of light left from the entrance "
     "of the passageway.  You are still following the stream but there is "
     "no longer any of those strange lillys growing beside it.  There are "
     "fewer stalagtites and stalagmites present here, it seems "
    "as if the walls and ceiling have been smoothed out somehow.  Back to the "
   "north west you see the entrance to the tunnels, and to the south west "
    "the passageway continues.\n\n");
add_item(({"stalagtite","stalagtites","stalagmite","stalagmites"}),"As you "
     "look at them, they seem to have been worn down somehow, "
     "for they are fewer in number and smaller than the ones at "
    "the entrance.\n\n");
add_item(({"walls","wall","ceiling","floor"}),"The walls and ceiling are still "
    "very smooth but they do not seem to be as slimy now.\n\n");
add_smell("air","The air still smells slightly musty, but not quite as damp as before.\n");
add_item(({"entrance","back","light"}),"As you look back at the entrace all "
    "you can see is a small speck of light from the outside.\n\n");
add_exit("southwest",UNDER +"under08","path");
add_exit("northwest",UNDER +"under01","path");
add_clone("/d/newbie/gnome/npcs/bat.c", 1);
}
