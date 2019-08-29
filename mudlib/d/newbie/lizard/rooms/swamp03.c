#include "path.h"
inherit ROOM+"baseroom";

void setup()
{
    my_setup();
    set_short("Realm of the Lizard :  Swamp");

    set_long("Realm of the Lizard : Swamp.\n\n"
      "You are standing knee deep in disgusting green water. "
      "There is a greasy film on the surface, the kind of thing that sticks to your clothes and doesnt come off. "
      "There is nothing living in this swamp. "
      "The once thriving trees that inhabited it are now skeletons, cruel reminders of how the swamp once was. "
      "The water itself is poisoned and polluted, all its resources sucked dry and left a poisonous waste land.\n\n");
    set_light(80);
    add_item("swamp","The water of the swamp is a dark poisonous murk. "
      "It supports no life in its depths. "
      "A thin greasy film covers its surface sticking to all it touches.\n\n");
    add_item("film","The surface of the water is covered with a thin greasy film that sticks to everything.\n\n");
    add_item("trees","The swamp supports no life, it is marred by grim skeletons of once flush and abundant trees.\n\n");
    add_exit("northeast",ROOMS"swamp05.c","path");
    add_exit("east",ROOMS"swamp04.c","path");
    add_exit("north",ROOMS"swamp02.c","path");
}
