#include "path.h"
 inherit "/std/room.c";

 void setup() {
set_short("Realm of the Orc:  Storage Room");
set_light(40);
   set_long("\n   Realm of the Orc:  Storage Room.\n\n"
            "     You are standing in a small room that is just "
            "south of the guardpost.  This room was likely a "
            "storage area, although there is absolutely nothing "
            "here.  There is a small hole in the ceiling with a "
            "rope dangling down from it.  The only other exits is "
            "to the north and west.  "
            "\n\n");
add_exit("north",DUNGEON +"dungeon08","door");
add_exit("west",DUNGEON +"dungeon12","door");
}
void init()
{
   ::init();
   add_action("do_climb","climb");
}
int do_climb(string str)
{
   if(str == "up" || str == "rope")
   {
      write("You climb upward through the darkness and stumble "
            "over the edge of the hole.\n");
      this_player()->move(ROOM+"orc18");
      this_player()->look_me();
      return 1;
   }
   else
   {
      write("Climb where?\n");
      return 1;
   }
}
