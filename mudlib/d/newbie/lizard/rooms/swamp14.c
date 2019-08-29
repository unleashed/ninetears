#include "path.h"
inherit ROOM+"baseroom";

void setup()
{
    my_setup();
    set_short("Realm of the Lizard :  Swamp");

    set_long("Realm of the Lizard : Swamp.\n\n"
      "You walk further along the winding path through the swamp. "
      "The trees are struggling to survive, living only off a poisonous swamp. "
      "The sun struggles to shine through the dense over hanging branches casting a gloom over you. "
      "The path makes a quick turn here to avoid plunging back into the murky spiteful swamp.\n\n");
    set_light(80);
    add_exit("northeast",ROOMS"swamp13.c","path");
    add_exit("northwest",ROOMS"swamp15.c","path");
}
