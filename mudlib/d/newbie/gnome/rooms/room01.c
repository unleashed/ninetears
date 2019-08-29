inherit "/std/outside";
#include "path.h"

void setup ()   {
set_short("Macedonia:  Leadge OVerlooking Shadow Valley");
set_light(40);
set_long("Macedonia:  Ledge Overlooking Shadow Valley\n\n"
         "   After the climb from below, you are now "
         "overpowered buy the beauty of Shadow Valley.  "
         "The ground here is nice and fertile, with "
         "bright green grass and colorful flowers "
         "growing wild.  Since this ledge was so "
         "difficult to find, you know the villagers "
         "of Macedonia do not frequently tend to this "
         "this ledge; so you feel there is something "
         "mysterious about this area, maybe even a bit "
         "magical.  Everything in the valley is within "
         "your eyesight from here.  From the rocky Mithril "
         "Mountains westward to the rooftops of the "
         "buildings of Macedonia eastward, you have a clear "
         "view of almost everything.  The trees of the "
         "Whispering Woods, the stillness of Lake "
         "Chicamocimoco, and the flowing waters of the Gnude "
         "River, everything fits together in perfect "
         "harmony."
         "\n\n");
add_clone(MISC+"stone.c",1);
add_item("lake", "This is a beautiful looking lake.  You are"
         " sent into a trance by the gentle lapping of the"
         " waves upon the shore.  You feel like you could stay"
         " here forever.\n");
add_item(({"river", "Gnude River"}), "The river slowly winds"
           " its way through Shadow Valley.  You spot a deer"
           " standing on the banks of the river getting a drink"
           " of the cool clear water.\n");
add_item(({"Mithril Mountains", "mountains"}), "You are in"
           " awe by the majestic beauty of the snow capped"
           " Mithril Mountains.  These are appear to be the"
           " highest mountains in all the realms.\n");
add_exit("down",VALLEY +"room02","path");
}
