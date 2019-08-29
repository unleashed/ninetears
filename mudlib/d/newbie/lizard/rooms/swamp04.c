#include "path.h"
inherit ROOM+"baseroom";

void setup()
{
    my_setup();
    set_short("Realm of the Lizard :  Swamp");

    set_long("Realm of the Lizard : Swamp.\n\n"
      "You are standing up to your knees in a wretched swamp. "
      "The water is a murky green color, looking malevolent and spiteful. "
      "There is a thin film lying on the surface, sticking to you and everything else it touches. "
      "The water is poisonous to the point where nothing can survive in its depths. "
      "Dark skeletons of once thriving trees are the only reminder of how it once was.\n\n");
    set_light(80);
    add_exit("west",ROOMS"swamp03.c","path");
    add_exit("northwest",ROOMS"swamp02.c","path");
    add_exit("north",ROOMS"swamp05.c","path");
    add_exit("northeast",ROOMS"swamp06.c","path");
    add_exit("east",ROOMS"swamp07.c","path");
    //   add_exit("southeast",ROOMS".c","path");
}
