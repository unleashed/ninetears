#include "path.h"
/*inherit "/std/outside"; */ inherit SWAMPGEN;

#define NUM 2

setup()
{
    set_light(60);
    set_short("Swamp");
    set_long("You stand in a swamp, before you stands a ruin of a tower "
      "from here it seems depressed. Thats probably due to the fact that the "
      "upper levels have been knocked askew at sometime in the past. "
      "However it does seem more habitable than the rest of this soggy hell. "
      "\n");
   add_property("no_undead",1);
    add_exit("south", HERE+"sw5", "road");
    add_exit("west", HERE+"sw4", "road");
    add_exit("east", HERE+"sw2", "road");
    add_item("swamp", "A totally unhealthy place. Bugs and treacherous ground "
      "everywhere you look. The stench is almost unbearable.\n");
    add_item("ground", "The ground is wet and treacherous.\n");

    add_clone(NPCS+"alligator.c",1);
    set_zone("swamp"); :: setup();
}
