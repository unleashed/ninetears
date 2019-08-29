inherit "/std/room.c";
#include "path.h"

void setup ()   {
    set_short("Macedonia:  Cavern of Plantipus\n");
    set_light(20);
add_property("no_undead",1);
    set_long("Macedonia:  Cavern of Plantipus\n\n"
"You have arrived at a large chamber in this cave.  To your east, you hear terrible grinding "
"sounds.  You get the impression that going this way maybe a BAD idea.  The only other "
"obvious exits are to the Northwest, where you hear water running, and to the West, where you "
"can see some faint light.  \n");
add_item(({"stalagmites","stalagtites"}),"These stalagmites and stalagtites are made of "
  "hardened calcium deposits over thousands of years.  They are gray in color and are dripping "
  "water in their growth.\n");
add_item("water","Water is dripping all around you, and you are already quite soaked from it.\n");
//     * senses *
add_smell(({"here","cave","air","area","mouth"}),"The air here is damp and stale smelling.\n");
add_sound(({"grinding sounds","sounds","sound","grinding"}),"The sounds come from the "
"East.  You have never heard anything like them before, and find the idea of going further "
"East rather uncomfortable.\n");
add_sound(({"water","cave","here","area","room"}),"All around you, water drips continually "
  "from every crack and crevice within the cave.\n");
add_feel(({"here","cave","area","stalagtite","stalagmite"}),"The entire area has a cold, "
  "damp, slimey feeling to it.  You quickly find yourself not wanting to touch more than you "
  "have to in here.\n");
add_clone(NPC+"rat.c",1);
add_exit("west",NORTHRMS +"cavern2.c","path");
add_exit("northwest",NORTHRMS +"cavern3.c","path");
add_exit("east",NORTHRMS +"cavern6.c","path");
}
