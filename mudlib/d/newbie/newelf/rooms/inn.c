//by Taggert.
#include "path.h";
inherit "/std/room";
void setup()
{
    set_short("Edgar's Inn. \n");
    set_light(LIGHT);
    set_long("\nEdgar's Inn. \n\n"
      "You step into the inn and notice immediately that the walls seem to be"
      " made of cracked stones instead of wood. The innkeeper, Edgar, is a "
      "human male, and builder of the building in which you stand. You begin "
      "to wonder why he hasn't repaired the walls.   \n\n");
    add_exit("east",ROOMS+"aaroc_center.c","door");
    add_item("walls","The wall is cracked and starting to crumble. "
      "It is possible that you could give it a good kick and it would come "
      "crumbling down.\n\n");
}
