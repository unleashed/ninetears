#include "path.h"
inherit "/std/room";

void setup()
{
        set_short("Living Room.");

        set_long("This is a well lived living room which you know "
                "well because this was your home when you were younger. "
                "There is a large bench covering the whole of one side "
                "of the room, and an assortment of various other stools etc. "
                "There is one exit down to the dangerous outside world, "
                "as well as stairs up and doorways to the east and west.\n");

        add_property("no_undead",1); set_light(100); 

        add_item("bench", "This is a pretty boring bench, old and worn.\n");

        add_item("stool", "This 3 legged stool is a basic stool...you see "
                "one the elfen trademanships mark on one of the legs.\n");
        

      add_exit("leave", NEW_NEWBIE+"elf/rooms/center.c", "door");
       add_exit("east", PATH+"h-elf2", "door");
       add_exit("west", PATH+"h-elf3", "door");
   modify_exit("leave",({"function","do_leave"}));
}

int do_leave()
{
   if(this_player()->query_property("guest"))
   {
      notify_fail("\nAs a welcome guest to the Final Realms you "
         "are being sent to our special guest area. "
         "Enjoy your visit with us.\n\n");
      this_player()->move(NEW_NEWBIE+"guests/rooms/intersection");
      this_player()->look_me();
      return 0;
   }
   return 1;
}

void add_equipment()
  {
  object boo;

  boo = clone_object("/baseobs/weapons/short_sword");
  boo->move(this_object());

  /* You can use boo for all the equipment..*/
  boo = clone_object("/baseobs/armours/cloak");
  boo->move(this_object());
  return;
}       
