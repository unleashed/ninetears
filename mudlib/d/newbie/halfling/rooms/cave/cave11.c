inherit "/std/room.c";
#include "path.h"
void setup()
{
set_short("Cave of Gloom:  Desolate Passage\n");
set_long("Cave of Gloom:  Desolate Passage\n"
"     This room is filled with piles of bones from dead halflings. The bones emit a stench "
"to the entire room.  Not only of death and decay, but of oppresive fear.  To the "
"North, there is a door with a light behind it.  To your West is a sloped passage "
"going down.  "
"The horrible noises that you have been hearing seem to come from behind the door to "
"the north.  "
"\n\n");

set_light(60);
add_item(({"bones","halflings"}),"These bones are broken and shattered all over the "
"floor.  Some still have sickening little bits of flesh sticking to them.  One skull, "
"with a huge hole in it, still bears a decayed eyeball that stares at you.\n");
add_item(({"skull","eyeball","eye","ball"}),"The skull and eyeball are too sick looking "
"too even think about touching.\n");
add_item("wall","Upon further inspection, the brown substance on the wall appears to be dried blood.\n");
add_item("moss","The phospherescent moss covers the cave in small patches"+
"imbedded into the ceiling providing barely enough light to see.\n");
add_feel("wall","The wall is slimy to the touch.\n");
 add_sound(({"sound","noises","north","door"}),"The noises are a grinding sound and come from the North.\n");
add_smell("cave","The cave smells musky and earthy, the way all caves smell.\n");
add_feel("moss","Try as you might, the moss is too high to reach.\n");
add_exit("west",CAVES+"cave10.c","path");
add_exit("north",CAVES+"endcave.c","door");
 modify_exit("north",({"function","go_north"}));
}
int go_north()
{
if(this_player()->query_level()<5)
{
notify_fail("You don't yet have the skill to pick the lock of this door.\n");
return 0;
}
tell_object(this_player(), "You laugh as you pick the lock and walk into the next room.\n");
return 1;
}
