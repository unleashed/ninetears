inherit "/std/room";
#include "path.h"

void setup ()   {
    set_short("Macedonia:  Cavern of Plantipus\n");
    set_light(20);
add_property("no_undead",1);
    set_long("Macedonia:  Cavern of Plantipus\n\n"
      "You are at the entrance of the cave.  Stalagtites and stalagmites surround you, and the "
      "sounds of water dripping can be heard all around you.  With what light there is, you "
"can just make out a passage going to the North and another going to the West.\n");
    add_item(({"stalagmites","stalagtites"}),"These stalagmites and stalagtites are made of "
      "hardened calcium deposits over thousands of years.  They are gray in color and are dripping "
      "water in their growth.\n");
    add_item("water","Water is dripping all around you, and you are already quite soaked from it.\n");
    //     * senses *
    add_smell(({"here","cave","air","area","mouth"}),"The air here is damp and stale smelling.\n");
    add_sound(({"water","cave","here","area","room"}),"All around you, water drips continually "
      "from every crack and crevice within the cave.\n");
    add_feel(({"here","cave","area","stalagtite","stalagmite"}),"The entire area has a cold, "
      "damp, slimey feeling to it.  You quickly find yourself not wanting to touch more than you "
      "have to in here.\n");
    add_clone(NPC+"spider.c",1);
    add_exit("west",NORTHRMS +"gnomech5.c","path");
    add_exit("north",NORTHRMS +"cavern2.c","path");
}
