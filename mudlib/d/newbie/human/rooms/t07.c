#include "path.h"
inherit HAVMAND+"track.c";
void setup()
{
    
    set_long("\nIsle of Havmand : Track\n\n"
    "This is a dusty little track in front of a group of small hovels. "
    "The hovel directly west from here looks to be a little bit cleaner "
    "and better maintained than most of the others in this tiny village. "
    "The sound of birdsong fills the air, and this is generally a much "
    "nicer place to be than most of this miserable little island. "
    "\n\n");
    add_sound(({"bird","birdsong","birds"}),"Birds are singing happilly in "
    "the trees nearby. \n");
    add_item("hovel","A neat, well-maintained little hovel, it really "
    "stands out amongst the other little buildings in this village. It "
    "even has a little garden of sorts by the door. "
    "\n");
    add_item("garden","A neat little garden around the doorway to this "
    "hovel. It is filled with sweet-smelling herbs. \n");
    add_item("herbs","A collection of herbs known for their healing powers, "
    "such as comfrey, thyme and dandelion and others you don't recognise.\n");

}
void init()
{
    add_exit("north",HAVMAND+"t06.c","path");
    add_exit("south",HAVMAND+"t08.c","path");
    add_exit("west",HAVMAND+"v05.c","path");
    add_exit("east",HAVMAND+"j13.c","path");

    ::init();
}

