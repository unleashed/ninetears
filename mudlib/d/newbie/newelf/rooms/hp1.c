#include "path.h"
inherit "/std/outside";

int pluck;

void setup()
{
    pluck = 5;
    set_light(60);

    add_property("no_undead",1);
    set_short("Hidden Path, Light Glade\n\n");

    set_long("Hidden Path, Light Glade\n\n"
      "You walk into a beautiful room with vines and branches hanging off"
      " of the trees. There are bright red berries hanging onm the vines."
      " It is likely that you could 'pluck' some of theses berries."
      "\n\n");


    add_item("vine", "The bush is a strange reddish plant.  As you "
      "look closer, you notice ripe berries growing on the "
      "branches.\n");
    add_item("berries", "The berries are ripe.  Maybe you should "
      "pluck some.\n");
    add_item("tree","The trees are covering the sky above you.\n");
    add_item("forest", "The forest seems to be inhabited by lots of wildlife. "
      "Everywhere you look, you see small animals moving around.\n");
    add_alias("bush","bushes");

    add_exit("south",ROOMS+"elf5.c","hidden");
    add_exit("north",ROOMS+"hp2.c","hidden");

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
    else {
	write("You pluck a ripe berry off the bush.\n");
	berry = clone_object(OBJ+"berry.c");
	berry->move(this_player());
	pluck = pluck -1;
	return 1;
    }
}
void reset()
{
    pluck = 5;
}

