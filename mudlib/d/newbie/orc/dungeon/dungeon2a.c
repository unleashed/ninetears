#include "path.h"
inherit CASTLE+"baseroom.c";

void setup() { my_setup();
set_short("Realm of the Orc:  Ornate Hallway");
set_light(40);
set_long("\n   Realm of the Orc:  Ornate Hallway.\n\n"
         "     You stand in a hallway of sorts.  It is long and wide "
         "with "
"high amount of labor involved in the construction. "
"There are some engravings placed into the walls. A few "
"meters into the hallway sits a stone carving. "
"  There is an odd odor lurking thoughout this room. "
"\n\n");
add_item("carving", "\n"
"  Its a huge stone carving of some kind of beast. The beast "
"has many arms and several eyes. It looks very hideous. "
"Underneath the stone-work are some words which you do not comprehend.\n");
add_smell(({"shit","odor","smell","odd odor"}),"\n"
"   It smells like.....like.....doo doo, yes thats right. "
" Smells like crap!\n");
add_item(({"wall","walls","engravings"}),"\n"
"  The engravings depict a large creature feeding on humans. "
"But what is odd is that the humans appear to be offering "
"their fellow humans to it! Underneath the depictions are some "
"human words...\n");
add_item(({"human words","human word","words","word"}),"\n"
"   OK, think now...what race are you?? ..ORC!!! \n"
" you can't read human words... *MUHAHAHAAAaaaa* \n");
add_exit("north",DUNGEON +"dungeon1a","door");
add_exit("south",DUNGEON +"dungeon3a","door");
}
