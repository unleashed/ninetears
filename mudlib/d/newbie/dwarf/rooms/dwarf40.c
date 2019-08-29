//  Dwarven Newbie Area:  Created By Mist   Fall 1994
  inherit "/std/room.c";
#include "path.h"

  void setup ()  {
set_short("Realm of the Dwarf:  Crawl Space");
set_light(10);
	set_long("\n   Realm of the Dwarf:  Crawl Space\n\n"
	 "     Here the ceiling is so low that you are forced to "
		"crawl on your hands and knees.  The floor is a little "
		"damp here, causing you to get a little wet and "
		"uncomfortable.  The cavern opens up to the northeast.  "
		"Perhaps you can stand upright there.  To the west you "
		"can see some light coming from a large room.  "
		"\n\n");
	add_item(({"water","droplets"}),"The ceiling is covered with "
		"large droplets of water.  They are falling onto the "
		"floor, causing it to be slippery. \n\n");
	add_item("ceiling","The ceiling here is very low and you are "
		"forced to crawl through here.  There are droplets of "
		"water suspended from the ceiling.  Each time you rub "
		"the ceiling, you get soaked by the cold, uncomfortable "
		"water.  \n\n");
	add_item("floor","The floor here is very wet, most likely due "
		"the large droplets of water that fall from the "
		"ceiling.  If you want to stay dry, you might want to "
		"move on.  "
		"\n\n");
	add_feel(({"cave","floor","ceiling"}),"The droplets of water "
		"on the ceiling and floor of the cave cause the cave "
		"to be cold and wet to the touch.  "
		"\n\n");
add_exit("west",ROOM+"guildroom.c","path");
add_exit("northeast",ROOM+"dwarf34","path");
}
