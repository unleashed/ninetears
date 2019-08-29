#include "path.h"
inherit "/std/outside";

void setup()
{
add_property("no_undead",1);
set_light(LIGHT);
set_short("Island of Maroek:  The Forest");
set_long("Island of Maroek:  Forest Path\n\n"
"You are deep within the Maroek forest.  To your north, you can just barely catch a glimpse "
"of a small mountain pushing out of the forest.  There is also a foul smell in the "
"air which you just noticed.  "
    "\n\n");

add_smell(({"here","foul","room"}),"The smell is barely noticable, but the breeze "
"seems to carry the scent of something long dead from the north.\n");

add_clone(CHAR+"buzzard.c",4);
add_exit("east",ROOMS+"half7.c","path");
add_exit("north",ROOMS+"half12.c","path");

}


