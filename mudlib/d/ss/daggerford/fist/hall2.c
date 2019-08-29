#include "path.h"

inherit "std/shop";

void setup() {
  set_short("Silver Fist Shop");
  set_long("This store services the many needs of the Band of the Silver "+
    "Fist.  You can do anything here that you could in any other shop.\n");
	set_light(80);
	add_exit("south", ROOM+"hall1", "door");
	set_store_room(ROOM+"st_room.c");
  add_item("counter", "A display counter for the wares of the shop.  Use the "+
    "command \"list\" to get a list of what they are.\n");
  add_item("object", "Use \"list\" to get a list of what is for sale.\n");
  add_alias("objects", "object");
}
