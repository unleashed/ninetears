//by Taggert
#include "path.h";
inherit "/std/room";

void setup()
{
    set_short("Bedroom. \n");
    set_light(55);
    set_long("You enter the bedroom and see that it looks as if"
      " noone has been in here for a long time. You notice that all "
      "the clocks in the room have been stopped. \n\n");
    add_item("clock","\nThe clocks in the room have been stopped"
      " at 3:25. You remember this as the time when your cousin died "
      "from the imp poison. \n");

    add_exit("south",ROOMS+"start_point.c","door");
}
