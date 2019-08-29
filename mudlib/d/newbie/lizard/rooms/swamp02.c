#include "path.h"
inherit ROOM+"baseroom";

void setup()
{
    my_setup();
    set_short("Realm of the Lizard :  Swamp");

    set_long("Realm of the Lizard : Swamp.\n\n"
      "You follow the path to the water's edge. "
      "The swamp is dark and steaming, as if inhabited by some unholy being that vamps the recources and moves on leaving a wasteland behind. "
      "The gnarled trees have long since died, poisoned by the now toxic water they lived in. "
      "The dead lake stretches itself out before you, in a long ribbon of death.\n\n");
    set_light(80);
    add_item("swamp","You are at the shore of a mucky swamp. "
      "The water is dark and murky, devoid of any life. "
      "A strange slimy film covers it sticking to everything.\n\n");
    add_item("film","A thin sticky film covers the surface of the water. "
      "It clings to anything it touches leaving it slimy and dirty.\n\n");
    add_item("trees","The trees here are skeletons of their former selves, a constant remider of the once thriving forest.\n\n");
    add_exit("southeast",ROOMS"swamp04.c","path");
    add_exit("east",ROOMS"swamp05.c","path");
    add_exit("south",ROOMS"swamp03.c","path");
    add_exit("northwest",ROOMS"swamp01.c","path");
}
