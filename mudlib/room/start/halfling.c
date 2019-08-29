#include "path.h"
inherit "/std/room";
object booklet;

void setup()
{
        set_short("Halfling Mountain home.");

        set_long("This is a small home which serves as a living room, "
                "bedroom and kitchen all in one. There "
                "is a small pile of ashes in the centre of the room, "
                "and various blankets and such like stacked neatly whereever "
                "space was found. Among these items are pans, sacks "
                "and god knows what else. There is one tunnel leading out to the large, "
                "dangerous world which becons you.\n");
                                                       
        add_property("no_undead",1); set_light(100); 

        add_item("home", "This is a smallish home well designed to "
                "offer protection against the harsh winters which "
                "are so common in this area. The walls are carved out of "
                "the rock and muddy hillside.\n");

        add_item("ashes", "These are the remnants of the last meal you had as "
                "a full family. There is a glint in the ashes which puzzles "
                "you.\n");

        add_item("blankets", "These are your standard old fashiond blankets.\n");
// add_exit("leave","/d/hoerk/havmand/newbies/t04.c","door");
add_exit("leave","/d/newbie/human/rooms/t04.c","door");
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
void reset()
{
  if(!sizeof(find_match("booklet", this_object())))
  {
    booklet = clone_object(BOOK);
    booklet->move(this_object());
  }
} /* void reset */

void dest_me()
{
if (booklet)
booklet->dest_me();
::dest_me();
}



void add_equipment()
  {
  object boo;

  boo = clone_object("/baseobs/weapons/dagger");
  boo->move(this_object());

  /* You can use boo for all the equipment..*/
  boo = clone_object("/baseobs/armours/cloak");
  boo->move(this_object());
  return;
}          
