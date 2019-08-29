#include "path.h"
inherit ROOM+"baseroom";

void setup()
{
    my_setup();
    set_short("Realm of the Lizard :  Swamp");

    set_long("Realm of the Lizard : Swamp.\n\n"
      "You are waist deep in murky green water. "
      "There is a film across the water, sticky and greasy getting on everything. "
      "The water itself is a poisonous waste, vamped of all its recources and left in ruin. "
      "The water supports no life, vague skeletons stand in rememberance of the thriving forest that has long since past.\n\n");
    set_light(80);
    add_item("water","The water is a poisonous waste, supporting no life in its depths. "
      "Its surface is covered by a thin slimy film, sticking to you and everything it touches. "
      "Dead skeletons of once flourishing trees line its banks.\n\n");
    add_item("film","The surface of the water is covered by a thin film. "
      "It is slimy and sticks to everything.\n\n");
    add_item("trees","The swamp is occupied by dead skeletons of trees, poisoned by the watery waste.\n\n");
    add_exit("east",ROOMS"swamp06.c","path");
    add_exit("southeast",ROOMS"swamp07.c","path");
    add_exit("south",ROOMS"swamp04.c","path");
    add_exit("southwest",ROOMS"swamp03.c","path");
    add_exit("west",ROOMS"swamp02.c","path");
}
