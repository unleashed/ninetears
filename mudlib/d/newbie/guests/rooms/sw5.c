#include "path.h"
/*inherit "/std/outside"; */ inherit SWAMPGEN;

#define NUM 2

setup()
{
    set_light(60);
    set_short("Swamp");
    set_long("You are in a swamp. "
      "The ground to the south is extremely wet, and since you're neither "
      "a lizard-man nor a fish, you can't go there. "
      "The stench of the swamp is all around you.\n");
   add_property("no_undead",1);
    add_exit("north", HERE+"sw3", "road");
    add_exit("west", HERE+"sw6", "road");
    add_exit("east", HERE+"sw1", "road");
    add_item("swamp", "A totally unhealthy place. Bugs and treacherous ground "
      "everywhere you look. The stench is almost unbearable.\n");
    add_item("ground", "The ground is wet and treacherous.\n");

    add_clone(NPCS+"lizardman.c",2);
    set_zone("swamp"); :: setup();
}
