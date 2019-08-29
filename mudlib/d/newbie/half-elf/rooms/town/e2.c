//Ljen feb -96

inherit "/std/outside";
#include "path.h"

void init()
{
    ::init();
    add_action("do_open", "open");
}


void setup()
{
    set_short("Jungle Town: Gate");
    set_long(" This is a quiet part of town, wich seems to be seldom"
      " visited. Infront of you a small gate blocks the way further."
      " When you stand here, you realize that the screams you heard"
      " in the wind elsewhere in town are gone now. But still you"
      " have a feeling that you are not alone. There is something"
      " strange here.. \n");

    set_light(80);

    add_item("gate", "A small wooden gate with spiderwebs covering it."	
      " Just infront of your eyes you can see a large keyhole,"
      " barely visible through all the dust and dirt.\n");

    add_item("keyhole", " A large keyhole, it seems like a key"
      " could perhaps do something.\n");

    add_item("ground", " The ground is covered with dust, there are"
      " nothing else here than your own footprints.\n");

    add_exit("west", TOWN+"d2.c","path");

}

void do_open(string str)
{
    object key;
    key = present("Gate Key",this_player());

    if(str == "gate")
    {
	if(!key) 
	{
	    write("You don't have the Gate key.\n"); 
	    return 1;
	}

	if((int)this_player()->query_level() != 5)
	{ 
	    write("You must learn more about the world before you can leave.\n"); 
	    return 1; 
	}

	write("You unlock the door with the Gate key.\n"); 
	this_player()->move("/d/sf/areas/monast/monpath2.c");
	this_player()->look_me();
	key->dest_me();
	return 1;
    }
    else
    {
	write("Open what?\n");
	return 1;
    }
}
