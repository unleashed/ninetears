#include "path.h"
inherit "/std/room";

void setup()
{
set_short("hallway");
set_long("You are standing at the 2nd floor landing of the temple.  A "+
        "set of stairs is in the northwest corner of the room, leading "+
        "either up or down.  The landing opens up to a balcony to the "+
        "south.\n");
add_item("stairs", "The lead either up or down.\n");
add_item(({"balcony", "landing"}), "The landing opens up to a balcony to the "+
          "south.\n");
set_light(90);
add_exit("down", ROOM+"lath3", "corridor");
/*add_exit("up", ROOM+"lath16", "corridor");*/
add_exit("south", ROOM+"lath15", "corridor");
/*
add_exit("east",ROOM+"shop.c","door");
*/

set_zone("lathander");
}
