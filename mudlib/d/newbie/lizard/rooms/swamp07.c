#include "path.h"
inherit ROOM+"baseroom";

void setup()
{
    my_setup();
    set_short("Realm of the Lizard :  Swamp");

    set_long("Realm of the Lizard : Swamp.\n\n"
      "You are standing up to your waist in a murky poisoned swamp. "
      "The water is a waste, vamped of its resources and left a poisonous wasteland. "
      "There is a thin disgusting film on the water that sticks to almost anything. "
      "The water is poisoned beyond the point that it can support life. "
      "Dead skeletons of a once florishing forest lay in grim remembrance of there past.\n\n");
    set_light(80);
    add_exit("east",ROOMS"swamp09.c","path");
    add_exit("northeast",ROOMS"swamp08.c","path");
    add_exit("north",ROOMS"swamp06.c","path");
    add_exit("northwest",ROOMS"swamp05.c","path");
    add_exit("west",ROOMS"swamp04.c","path");
    // add_exit("south",ROOMS".c","path");
}
