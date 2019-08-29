#include "path.h"
inherit ROOM+"baseroom";

void setup()
{
    my_setup();
    set_short("Realm of the Lizard :  Swamp");

    set_long("Realm of the Lizard : Swamp.\n\n"
      "You are standing on a muddy path winding through the swamp. "
      "It is dark here, the sun struggles to show through the dense, half dead trees. "
      "The trees struggle for there very existance against the malevolent poison of the nearby swamp.\n\n");
    set_light(80);
    add_exit("southeast",ROOMS"swamp14.c","path");
    add_exit("southwest",ROOMS"swamp16.c","path");
}
