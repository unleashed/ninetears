#include "path.h"
inherit ROOM+"baseroom";

void setup()
{
    my_setup();
    set_short("Realm of the Lizard :  Swamp");

    set_long("Realm of the Lizard : Swamp.\n\n"
      "You have come to a small opening in the trees. "
      "The path ends into a small grassy area. "
      "The grass is brown, like the trees, struggling to stay alive in this hostile environment. "
      "The sun shines through the hole in the tree tops to releive the grove of the gloom of the rest of the swamp.\n\n");
    set_light(80);
    add_exit("northeast",ROOMS"swamp15.c","path");
    add_clone(CHARS+"zzarg.c",1);
}
