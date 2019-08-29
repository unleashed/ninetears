inherit "/std/room";
#include "path.h"

void setup ()   {
add_property("no_undead",1);
set_short("Realm of the Gnome:  Macedonian Tunnel");
set_light(40);
set_long("\nRealm of the Gnome:  Macedonian Tunnel\n\n"
	 "     This is a large cavernous area of the tunnel.  It is made "
 "of packed earth, and it feels quite warm and dry in here.  Were it "
"not for the wolves you might feel quite comfortable resting here for a "
"spell.  As it is you think you might want to head to your south.\n\n");
add_item(({"wall","floor","walls","ceiling"}),"As you look "
"around you, you can see how tightly packed the earth is.  It seems "
"as if this area has been dug out by hand.\n\n");
add_exit("south",UNDER +"under15","path");
add_clone(CHAR+"wolf.c",2);
}
