inherit "/std/room";
#include "path.h"

void setup ()   {
set_short("Macedonia:  Fydor's Smithy");
set_light(40);
set_long("Macedonia:  Fydor's Smithy\n\n"
         "   The entire building is almost completely "
         "covered by dirt and dust because Fyodor has not "
         "cleaned this smithy in ages.  But most of the "
         "customers in this area do not really care a whole "
         "lot since he can repair weapons better than anyone "
         "in Macedonia.  The building is rather plain, but along "
         "all the walls there are different types of tools "
         "hanging and shelves filled with equipment for sale "
         "and to be fixed."
         "\n\n");
add_item(({"dirt", "dust"}), "The dust in the place is really piled"
        " on thick.  It's a wonder Fyodor doesn't get sick from"
        " breathing that mess.\n");
add_item("tools", "These tools appear to have been used many times"
         " making tools for the villagers of Macedonia.\n");
add_item(({"walls", "shelves"}), "The walls are covered with many"
         " Fyodor's favorite tools for working with metal.\n");
add_clone(NPC+"smith.c",1);
add_exit("south",VALLEY +"gnome14","path");
}
