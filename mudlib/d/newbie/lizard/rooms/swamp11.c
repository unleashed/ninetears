#include "path.h"
inherit ROOM+"baseroom";

void setup()
{
    my_setup();
    set_short("Realm of the Lizard :  Swamp");

    set_long("Realm of the Lizard : Swamp.\n\n"
      "You are knee deep in a green murky swamp. "
      "The surface of the swamp is covered with a slimy film that sticks to everything it touches. "
      "The water is dark and gloomy, supporting no life. "
      "Dark skeletons are all thats left of a once thriving forest.\n\n");
    set_light(80);
    add_exit("west",ROOMS"swamp09.c","path");
    add_exit("northwest",ROOMS"swamp08.c","path");
    add_exit("north",ROOMS"swamp10.c","path");
    //   add_exit("east",ROOMS"path01.c","path");
    //   add_exit("south",ROOMS"path15.c","path");
}
