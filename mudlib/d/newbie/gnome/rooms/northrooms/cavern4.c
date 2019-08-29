inherit "/std/room";
#include "path.h"

int mush;
void reset()
{
mush = 4;
}
void setup ()   {
    set_short("Macedonia:  Cavern of Plantipus\n");
    set_light(20);
add_property("no_undead",1);
    set_long("Macedonia:  Cavern of Plantipus\n\n"
      "You have arrived in a very small room with stalagtites and stalagmites all around.  "
      "In the middle of the room, there is a fountain of marble, with water bubbling from deep "
      "within the earth.  The only way out of this room, is back to the South.\n");
    add_item(({"stalagmites","stalagtites"}),"These stalagmites and stalagtites are made of "
      "hardened calcium deposits over thousands of years.  They are gray in color and are dripping "
      "water in their growth.\n");
    add_item("water","Water is dripping all around you, and you are already quite soaked from it.\n");
    add_item("fountain","The fountain streams forth from deep within the earth, the waters of "
      "it seem to look VERY refreshing.\n");
    //     * senses *
    add_smell(({"here","cave","air","area","mouth"}),"The air here is damp and stale smelling.\n");
    add_sound(({"water","cave","here","area","room"}),"All around you, water drips continually "
      "from every crack and crevice within the cave.\n");
    add_feel(({"here","cave","area","stalagtite","stalagmite"}),"The entire area has a cold, "
      "damp, slimey feeling to it.  You quickly find yourself not wanting to touch more than you "
      "have to in here.\n");
    add_exit("south",NORTHRMS +"cavern3.c","path");
}
void init()
{
    add_action("do_drink","drink");
    ::init();
}
int do_drink(string str)
{
    if(str != "water")
    {
	return(0);
    }
    if(mush <= 0)
{
write("the magical powers of this fountain are exhausted.\n");
	return 1;
    }
    {
	write("You take a small sip of the water from the spring, and magical energy rushes through "
	  "your body.  You feel MUCH healthier!\n");
	say(this_player()->query_cap_name()+" takes a sip of water from the fountain.\n",
	  this_player() );
	this_player()->adjust_hp(random(3)+3 );
mush = mush - 1;
	return 1;
    }
}
