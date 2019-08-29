#include "path.h"
inherit "/std/room";

void setup()
{
        set_short("Small Room.");

   set_long("     You stand in a dark and small room in the commoner's "
	"quarters of your house.  You have spent all of your years "
	"in these rooms, serving the high and noble members.  To "
	"the east, lies a door leading to the room where the commoners "
	"sleep, when they are allowed.  The other exit, would take "
	"you to the training place for drow, where you will prove "
	"if you are worthy of something beyond this pitiful place.\n\n");

	add_property("no_undead",1);
	set_light(20);

   add_exit("leave", "/d/newbie/drow/maze/maze","door");
   add_exit("east", PATH+ "drow2", "door");
   modify_exit("leave",({"function","do_leave"}));
   add_clone("/baseobs/weapons/short_sword",1);
   add_clone("/d/newbie/drow/armour/piwafwi",1);
   add_clone(BOOK,1);

}
int do_leave()
{
   if(this_player()->query_property("guest"))
   {
      notify_fail("\nAs a welcome guest to the Final Realms, you are being "
         "sent to our special guest area. Enjoy your visit with us.\n\n");
      this_player()->move(NEW_NEWBIE+"guests/rooms/intersection.c");
      this_player()->look_me();
      return 0;
   }
   return 1;
}


