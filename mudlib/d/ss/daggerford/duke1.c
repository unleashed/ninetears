#include "path.h"
#include "/std/outside.c"
inherit CITYROOM;

#define NUM 3

setup()
{
set_light(60);
set_short("Duke's Way");
set_long("You are on Duke's Way. The way continues to the north. "+
 "to the south is Tanner's Way, and you hear sound of a market there. "+
 "Far to the north you can barely make out a castle.\n");
add_exit("north",ROOM+"duke2", "road");
add_exit("south",ROOM+"tanner1", "road");
add_item("castle",
 "It's a high stone keep, surrounded by "+
 "a stone wall, situated on a hillside.\n");
set_monster(NUM, "city");
set_zone("city");
}
