#include "path.h"
inherit "/std/outside";
int found;
object chain;
object sword;

void setup()
{
add_property("no_undead",1);
set_light(LIGHT);
set_short("Island of Maroek:  Forest\n");
set_long("Island of Maroek:  Forest Path\n\n"
"You have arrived in a dark corner of the forst.  There is a large rock on one "
"side of this small clearing that you swear looks like a large bed.  Dead leaves carpet the "
"entire forest floor crunch underfoot.  "
    "\n\n");

add_item("canopy","The canopy is made of the immense trees' leaves and nearly cuts "
"off all the light from above.\n");
add_item("trees","The trees of this area seem to be darker and more menacing than "
"anywhere else in the forest.\n");
add_item("rock","You could almost swear this rock looked like a large, but hard, bed.\n");

add_exit("southeast",ROOMS+"half19","path");
}


void reset()
{
found = 0;
}
void dest_me()
{
::dest_me();
}
int do_search(string str)
{
if(! found)
{
write("You search around the rock, as Mari suggested, and discover a leather satchel.  "
"inside you find an old Halfling Bastard sword and a Halfling Chainmail.  \n");

say(this_player()->query_cap_name()+" scrounges around through the leaves\n",this_player());

found = 1;

chain = new(ARMOUR+"chainmail.c");
chain->set_short("Halfling Chainmail");
chain->set_long("This Chainmail is just like any other chainmail, except that it "
"has been taken in on the sides and along the bottom to fit a halfling a little "
"better.  No pun intended.\n");
chain->move(this_object());

sword = new(WEAPONS+"bastard_sword.c");
sword->set_short("halfling bastard sword");
sword->set_long("This weapon, normally too cumbersome for some humans, has been "
"shortened some to fit the needs and strength of a Halfling.  \n");
sword->move(this_object());
}
else
{
write("You scrounge around in the leaves, but don't see anything.\n");
}
return 1;
}
