#include "path.h"
inherit ROOM+"baseroom";

void setup()
{
    my_setup();
    set_short("Realm of the Lizard :  Swamp");

    set_long("Realm of the Lizard : Swamp.\n\n"
      "You are standing up to your waist in dead murky water. "
      "There is a thin film on the surface of the water, sticking to you and your clothes. "
      "The water itself is a poison[?1;0cous waste, able to support no life in its depths. "
      "Grim skeletons of once thriving trees mar the banks.\n\n");
    set_light(80);
    add_exit("east",ROOMS"swamp10.c","path");
    add_exit("southeast",ROOMS"swamp11.c","path");
    add_exit("south",ROOMS"swamp09.c","path");
    add_exit("southwest",ROOMS"swamp07.c","path");
    add_exit("west",ROOMS"swamp06.c","path");
}
