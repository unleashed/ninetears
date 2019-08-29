#include "path.h"
inherit ROOM+"baseroom";

void setup()
{
    my_setup();
    set_short("Realm of the Lizard :  Swamp");

    set_long("Realm of the Lizard : Swamp.\n\n"
      "You are walking along a winding muddy path through the dense trees. "
      "The trees here are near death, constantly struggling with the poisonous swamp. "
      "It is very dark, the sun trying to shine through the small holes in the dense foliage. "
      "The path curves again, bypassing a large ironwood tree, too stuborn to be removed.\n\n");
    set_light(80);
    add_exit("southeast",ROOMS"swamp12.c","path");
    add_exit("southwest",ROOMS"swamp14.c","path");

}
