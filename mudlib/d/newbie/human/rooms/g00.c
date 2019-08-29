#include "path.h"
inherit "/std/outside";
int found;
object axe;
void setup()
{
   found = 1;
    add_property("no_undead",1);
    set_light(LIGHT);
    set_short("Isle of Havmand: Gate.");
    set_long("\n   Isle of Havmand: Gate.\n"
    "You are standing before a huge wooden gate built into the castle wall. "
    "It looks like the back entrance to the castle, and you can only assume it "
    "was used by the villagers who had some reason to enter the castle and for "
    "the delivery of supplies. It has been firmly shut and the iron bands on it "
    "have rusted. To your left is a pile of chopped wood ready for a fire. "
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
add_item("axe","The axe is stuck in a log of the woodpile.  You could probably pull "
"it loose.\n");

    add_exit("east",HAVMAND+"t09.c","path");
}
void init()
{
    ::init();
    add_action("do_take","take");
add_action("do_take","pull");
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
write("You give the axe a mighty heave, and drop it in an effort to regain your balance.\n");
say(this_player()->query_cap_name()+" yanks the axe from the woodpile, dropping "
"it as they nearly fall over a loose log.\n",this_player());

    found = 1;
   axe = new(WEAPON+"wood_axe.c");
    axe->move(this_object());
    }
    return 0;
}
