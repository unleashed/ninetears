#include "path.h"
inherit ROOM+"baseroom";

void setup()
{
    my_setup();
    my_setup();
    set_short("Realm of the Lizard :  Swamp");

    set_long("Realm of the Lizard : Swamp.\n\n"
      "You are standing waist deep in a murky swamp. "
      "The water itself is murky and dark, like the darkest night. "
      "There is a thin greasy film on the surface of the water that sticks to everything it touches. "
      "The water is a poisoned waste, supporting no life. "
      "Dark trees once flourishing are now skeletons, a grim reminder of the past.\n\n");
    set_light(80);
    add_exit("east",ROOMS"swamp08.c","path");
    add_exit("southeast",ROOMS"swamp09.c","path");
    add_exit("south",ROOMS"swamp07.c","path");
    add_exit("southwest",ROOMS"swamp04.c","path");
    add_exit("west",ROOMS"swamp05.c","path");
}
