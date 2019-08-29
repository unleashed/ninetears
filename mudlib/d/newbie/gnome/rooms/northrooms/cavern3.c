inherit "/std/room";
#include "path.h"

void setup ()   {
    set_short("Macedonia:  Cavern of Plantipus\n");
    set_light(20);
add_property("no_undead",1);
    set_long("Macedonia:  Cavern of Plantipus\n\n"
      "You are in the Northern most section of the cave.  Sounds of moving water come from somewhere in this room.  "
      "There is a passage to the South from which you can see faint light, and another to the "
      "Southeast.  "
      "\n\n");
    add_item(({"stalagmites","stalagtites"}),"These stalagmites and stalagtites are made of "
      "hardened calcium deposits over thousands of years.  They are gray in color and are dripping "
      "water in their growth.\n");
add_item("north","You notice a path to your north, from which can be heard water flowing.\n");
    add_item("water","Water is dripping all around you, and you are already quite soaked from it.\n");
    //     * senses *
    add_smell(({"here","cave","air","area","mouth"}),"The air here is damp and stale smelling.\n");
    add_sound(({"water","here","area","room","moving","moving water"}),"The sounds seem to be "
      "coming from a small gap between the rocks to your North which you didn't notice before.\n");
    add_feel(({"here","cave","area","stalagtite","stalagmite"}),"The entire area has a cold, "
      "damp, slimey feeling to it.  You quickly find yourself not wanting to touch more than you "
      "have to in here.\n");
    add_exit("south",NORTHRMS +"cavern2.c","path");
add_clone(NPC+"rat.c",2);
add_exit("north",NORTHRMS +"cavern4.c","hidden");
add_exit("southeast",NORTHRMS +"cavern5.c","path");
}
