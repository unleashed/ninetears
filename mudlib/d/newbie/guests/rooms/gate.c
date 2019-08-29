#include "path.h"
inherit "/std/outside";
int found;
object axe;
void setup()
{
    add_property("no_undead",1);
    set_light(85);
    set_short("Isle of Havmand: Gate.");
    set_long("\n   Isle of Havmand: Gate.\n"
    "You are standing before a huge wooden gate built into the castle wall. "
    "It looks like the back entrance to the castle, and you can only assume it "
    "was used by the villagers who had some reason to enter the castle and for "
      "the delivery of supplies. To the side is a pile of chopped wood. "
    "\n\n");
    set_night_long("\n   Isle of Havmand: Gate.\n"
    "The castle wall looms darkly above you. A darker rectangle shape is set "
    "into the wall and looks like it might be a gate. You knock your shin "
    "painfully on something wooden when you move. "
    "\n\n");
    add_item("gate","A huge wooden gate, with iron bands across it, it is "
    "impossible to open from here.\n");
    add_item(({"wall","castle","castle wall"}),"A huge stone wall looming high above "
    "you. The gate is built into the wall.\n");
    add_item(({"wood","woodpile"}),"A pile of neatly chopped wood stacked "
    "beside the gate. There is an axe sitting on top.\n");
    add_feel("shin","Ouch! that really hurt.");
    add_item("axe","An axe used for chopping wood.");

}
void init()
{
    add_exit("east",HERE+"con01.c","path");
   add_exit("west",HERE+"den08","path");
    add_action("do_take","take");
    add_action("do_take","get");
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
   write("You reach across the woodpile for the axe.\n");
    say(this_player()->query_cap_name()+" tries to get an axe from the woodpile.\n",this_player());

    found = 1;
   axe = new(WEAPON+"wood_axe");
    axe->move(this_object());
    }
    return 0;
}
