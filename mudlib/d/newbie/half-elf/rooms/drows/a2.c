//Ljen nov -96

inherit"/std/room";
#include "path.h"

void init()
{
::init();
add_action("do_crawl", "crawl");
}


void setup()
{
   set_light(60);

   set_short("Drow tunnel");

   set_long("This looks like the entrance to a small tunnel, the"
            " air is hard to breathe in, warm and moist."
            " It is dark in here, hard to see where to go, but"
            " you can feel the presence of something evil in here.."
            " The air, the athmosphere in here sends shivers down"
            " your spine. You can barely see the exit back to"
            " safety in the town, but if you want to risk your life"
            " you can follow a small path leading further into this"
            " darkand spooky tunnel. You can see something small"
	    " on the wall above your head, hard to make out what it is though.\n");

   add_exit("east", DROWS+"b2.c", "path");

   add_item("wall", "As you examine the wall closer, you can see a small"
	    " hole in the wall. Perhaps you could squeeze out there?\n");

   add_feel("athmosphere", "Something evil is in here, you are sure about it!\n");

   add_smell("air", "It smells dark, moist, and there is also one other scent,"
             " you are not sure, but if you didn't know better, it could be drow.. \n");
   
   add_item("hole", "A small dark hole, with a tiny bit of light in the"
            " end. Perhaps this will take you out? If you just could crawl into it.. \n");



 }


void do_crawl(string str)
{
        if(str !="hole")
           {
               notify_fail("You want to crawl where?\n");
               return 0;
           }
        if(str =="hole")
           {
               write("\nYou wiggle and suddenly you manage to squeeze your"
	             " body through that small hole."
                     " When you look around you see that you are back"
	             " in the orchard.\n\n");
               this_player()->move(TOWN+"d1.c");
               this_player()->look_me();
               return 1;
           }
}

