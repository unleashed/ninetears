# include "path.h"
inherit "/std/room";
int found;
object door;
void setup()
{
    add_property("no_undead",1);
    set_short("Isle of Havmand: Hovel.");
    set_light(60);
   set_long("\nIsle of Havmand : Hovel\n\n"
    "This miserable little hovel is basically a wreck. There are holes in the "
    "roof and walls, and the door hangs loosely on its hinges. There is nothing "
    "in here that could be described as furniture and the floor is covered "
    "with dead leaves and twigs blown in from outside. "
    "\n\n");
    add_item("holes","You can see through the holes in the roof to the sky, and "
    "through the holes in the walls to the jungle outside.\n");
    add_item("sky","Blue when its fine, grey when its raining, and black at night.\n");
    add_item("jungle","Thickly growing trees which cover most of the island.\n");
    add_item("roof","A thinly thatched roof with big holes where the thatch has "
    "blown away.\n");
    add_item("walls","The walls of the hovel have been made from wood, but some of "
    "the planks are missing, leaving big holes.\n");
add_item("door","A wooden door which hangs loosely from its frame.  A simple pull "
"would be all it would take to knock it off its leather hinges.\n");
    add_item("hinges","The hinges are made from leather.\n");
add_item(({"leaves","twigs","rubbish","floor"}),"The floor is covered with rubbish "
"which has been blown or tracked in from the jungle.  \n");

}
void init()
{
    add_exit("east",HAVMAND+"t08.c","path");
add_action("do_take","pull");
add_action("do_take","take");
    ::init();
}
void reset()
{
    found = 0;
}
void dest_me()
{
    ::dest_me();
}
int do_take(string str)
{
    if(!found)
    {
        write("With a mighty heave you wrench the door off its leather hinges.\n");
        say(this_player()->query_cap_name()+" gets a door from the hovel.\n",this_player());
        found = 1;
door=new(OBJ+"door.c");
        door->move(this_object());
        return 1;
    }
    return 0;
}



