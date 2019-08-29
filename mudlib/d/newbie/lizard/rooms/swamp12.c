#include "path.h"
inherit ROOM+"baseroom";

void setup()
{
    my_setup();
    set_short("Realm of the Lizard :  Swamp");

    set_long("Realm of the Lizard : Swamp.\n\n"
      "You are on a muddy path leading down to a steaming swamp. "
      "The trees around you are dead, feeding off the poisonous water of the dead lake. "
      "It is very dark and gloomy, the sun struggling to peek through the holes in the think branches. "
      "The path turns to your left, skirting a deadly quicksand pit to your right.\n\n");
    set_light(80);
    add_exit("southwest",ROOMS"swamp10.c","path");
    add_exit("northwest",ROOMS"swamp13.c","path");
}
