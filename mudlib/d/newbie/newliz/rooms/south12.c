#include "path.h"

inherit "/std/outside";
void setup()
{
    set_short("Lizard's Island:  Beach\n");
    set_light(LIGHT);
    add_property("no_undead",1);
    set_long("Lizard's Island:  Beach\n\n"
"     This is the island's Southern-most point.  Ocean surrounds you in every "
"direction save to the West.  Waves crash violently on all sides, except for the "
"North, where there is a relative calm between two massive rocks.  "
      "\n\n");

    add_item("shells","These shells are common all over the island and are frail to "
      "the touch.\n");
    add_item("sun","The sun beats down from above.  It feels good to a lizard, such "
      "as yourself.\n");
    add_feel(({"sand","floor","ground"}),"The ground is very hot, and the sand hot "
      "to the touch of your feet.\n");
add_item("waves","The waves are crashing down on the nearby rocks, sending a spray "
"of water nearly 20 feet into the air with each impact.\n");
add_item("spray","The spray is flung so high up that it is little more than a "
"gentle mist when it reaches your scaly skin.\n");
add_feel(({"spray","mist","ocean"}),"Due to the tropical nature of this island, the "
"water and it's spray from hitting the rocks are all very warm.\n");

    add_exit("west",ROOMS+"south11.c","path");

}


void init()
{
    add_action("do_dive","dive");
    add_action("do_dive","swim");
    ::init();
}
int do_dive(string str)
{
    if(str == "ocean")
    {
	if(this_player()->query_property("diver"))
	{
	    TP->move(WATER+"water1.c");
	    TP->look_me();
	    return 1;
	}
	else
	{
write("You're not sure it's safe to dive in here.\n");
	    return 1;
	}
}
	else
	{
	    write("Dive into what?\n");
	    return 1;
	}
    }


