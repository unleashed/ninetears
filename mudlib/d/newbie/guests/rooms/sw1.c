#include "path.h"
inherit SWAMPGEN;

#define NUM 2

setup()
{
    set_light(60);
    set_short("Swamp");
    set_long("You are in a swamp. There is an exit from the swamp to "
      "the east. The stench of the swamp is all around you.\n");
    add_property("no_undead",1);
    add_exit("north", HERE+"sw2", "road");
    add_exit("west", HERE+"sw5", "road");
    add_exit("east",HERE+"con02.c","path");
    add_item("swamp", "A totally unhealthy place. Bugs and treacherous ground "
      "everywhere you look. The stench is almost unbearable.\n");
    add_item("ground", "The ground is wet and treacherous.\n");

    add_clone(NPCS+"toad.c",2);
    set_zone("swamp"); :: setup();
    :: setup();
}
