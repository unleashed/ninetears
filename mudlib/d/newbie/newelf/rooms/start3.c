//by Taggert
#include "path.h";
inherit "/std/room";

void setup()
{
    set_short("Empty Room. \n");
    set_light(55);
    set_long("This is just a small storage room"
      " that has never been used. \n\n");

    add_exit("north",ROOMS+"start_point.c","door");
}
