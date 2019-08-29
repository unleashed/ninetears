#include "path.h"
inherit "/std/room";
object booklet;

void setup()
{
        set_short("Lizard man hut.");

        set_long("This is a little small hut which served as a home "
                "for you, outside you see a wet dark and damp swamp. "
                "The hut you are in is damp and the cool swamp air "
                "drifts in through the window. There is a small table "
                "in the center of the hut, upon which is a dirty"
                "piece of tattered paper folded into a booklet. There "
                "is a pile of oddments and pots which look strange. "
                "The only exit seems to lead to the real world.\n");
                                                       
        add_property("no_undead",1); set_light(70); 
        add_item("table", "Hmmm well this is a table, what did you expect? "
                          "It is cold and damp.\n");
        add_item("pots","These are old cooking utensiles of no use.\n");
        add_item("oddments", "This is a large pile with the odd glint here or there, "
                              "but you can't tell much more at the moment.\n");
   add_exit("leave",NEW_NEWBIE+"lizard/rooms/lizard26.c","door");
   modify_exit("leave",({"function","do_leave"}));
}

int do_leave()
{
   if(this_player()->query_property("guest"))
   {
      notify_fail("\nAs a welcome guest to the Final Realms "
         "you are being sent to our special guest area. "
         "Enjoy your visit with us.\n\n");
      this_player()->move(NEW_NEWBIE+"guests/rooms/intersection.c");
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

  boo = clone_object("/baseobs/weapons/trident");
  boo->move(this_object());

  /* You can use boo for all the equipment..*/
  boo = clone_object("/baseobs/armours/cloak");
  boo->move(this_object());
   boo = clone_object("/baseobs/misc/torch");
   boo->move(this_object());
  return;
}          
