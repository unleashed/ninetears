#include "path.h"
inherit "/std/room";
object booklet;

void setup()
{
        set_short("Goblins Pit");

        set_long("This is a little small pit which serves as a home "
                "for you poor races. There is not much here but you "
                "may be lucky. There is a pile of ashes in one corner "
                "with a few old blackened pans arround them. There is a  "
                "single tiny stool near the ashes, upon which is a small "
                "piece of tattered paper folded into a booklet. There is a "
                "largish pile of oddments in the opposite corner, god knows what "
                "you will find there. The only exit seems to lead to the "
                "large, dangerous world.\n");
                                                       
        add_property("no_undead",1); set_light(20); 

        add_item("Pit", "This is a mud lined pit...good eh?.\n");

        add_item("Ashes", "Hmmm well these are ashes, what did you expect? "
                          "They are cold and grey... a bit like death.\n");
                       
        add_item("Pots","These are old cooking utensiles of no use.\n");

        add_item("Oddments", "This is a large pile with the odd glint here or there, "
                              "but you can't tell much more at the moment.\n");
      add_exit("leave", NEW_NEWBIE+"goblin/rooms/entrance.c", "door");
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

