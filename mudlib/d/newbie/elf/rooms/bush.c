#include "path.h"
inherit "/std/outside";

int pluck;

void setup()
{
    pluck = 5;
    set_light(60);

    add_property("no_undead",1); set_short("Realm of the Elf:  Strange Glade");
    set_long("\n   Realm of the Elf:  Strange Glade.\n\n"
      "     You are in a strange glade deep in the High Forest.  "
      " Your eyes are drawn to the bizzare looking bush in the "
      "center of the glade.  Your elven knowledge of forest life "
      "tells you that the bush is magical and probably has "
      "special properties."
      "\n\n");
    add_item("bush", "The bush is a strange reddish plant.  As you "
      "look closer, you notice ripe berries growing on the "
      "branches.\n");
    add_item("berries", "The berries are ripe.  Maybe you should "
      "pluck some.\n");
    add_item("tree","The trees are covering the sky above you.\n");
    add_item("forest", "The forest seems to be inhabited by lots of wildlife. "
      "Everywhere you look, you see small animals moving around.\n");
    add_alias("bush","bushes");

    add_exit("west", ROOM+"fo1", "road");

    set_zone("forest"); 
}

void init()
{
    add_action("pluck_berry","pluck");
    ::init();
}

object berry;
int pluck_berry()
{
    if(pluck<=0)
    {
	write("Sorry, the rest of the berries are too unripe to pick right now.\n");
	return 1;
    }
    write("You pluck a ripe berry off the bush.\n");
    berry = clone_object(OBJ+"berry.c");
    berry->move(this_player());
    pluck = pluck -1;
    return 1;
}
void reset()
{
    pluck = 5;
}

