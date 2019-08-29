#include "path.h"
#include "/std/outside.c"
inherit CITYROOM;

#define NUM 3

setup()
{
 set_light(60);
 set_short("Wall street");
 set_long("You are on Wall street.  Wall street follows the city walls to "+
          "the north (ending at Delfen's Tower) and south (past the western "+
          "city gates).  The walls of the city press in all around you.\n");
 add_exit("north", ROOM+"delfen", "road");
 add_exit("south", ROOM+"wgate", "road");
 set_monster(NUM, "city");
 set_zone("city");
}
