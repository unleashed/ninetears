#include "path.h"
#include "/std/outside.c"
inherit CITYROOM;

#define NUM 1

setup()
{
 set_light(60);
 set_short("Wall Street");
 set_long(
"You are on Wall street.  The street continues to the east and west.\n"+
"To the north is the Temple of Tymora. It acts as a clerics' guild.\n");

 add_exit("east", ROOM+"wall3", "road");
 add_exit("west", ROOM+"wall1", "road");
 add_exit("north", TYMORA+"tymgates", "road");

 add_alias("shrine of tymora", "shrine");
 add_alias("tymora", "shrine");
 add_item("shrine",
"The shrine seems to be quite randomly coloured and built. For some "+
"reason this fails to get you in a proper religious mood, but nevertheless "+
"it is really quite stunning as shrines go.\n");

 set_zone("city");
 set_monster(NUM, "city");
}


