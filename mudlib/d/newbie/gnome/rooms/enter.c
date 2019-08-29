inherit "/std/room";
#include "path.h"
object helmet;
object quarterstaff;
object leather;

void setup ()   {
        set_short("Gnome Household.");

        set_long("This is a small shack which serves as a living room, "
                "bedroom and kitchen all in one. You recognise the room "
                "when you realise it was where you were brought up. There "
                "is a small pile of ashes in the centre of the shack, "
                "and various blankets and such like stacked neatly whereever "
                "space was found. Among these items are blankets, sacks "
               "and god knows what else. There is one exit down to the large, "
                "dangerous world which beckons you.\n");
                                                       
        set_light(100); 

        add_item("shack", "This is a smallish shack well made but still "
                "very little protection against the harsh winters which "
               "are so common in this area. The walls are made of interweaved "
                "hay.\n");

        add_item("ashes", "These are the remnants of the last meal you had as "
                "a full family. There is a glint in the ashes which puzzles "
                "you.\n");

        add_item("blankets", "These are your standard old fashioned blankets.\n");
add_exit("down",VALLEY +"gnome08","path");
add_clone("/d/newbie/gnome/items/cabinet.c",1);
}
void init()
{
   add_action("open_it","open");
   ::init();
}
int open_it(string str)
{
   if(str == "cabinet")
   {
      if(this_player()->query_property("GNOME_EQ"))
      {
         write("As you reach into the cabinet, you suddenly "
               "remember that you have gotten the equipmnt from "
            "here already.\n");
         return 1;
      }
      else
      {
         write("You open the door to the cabinet to find a "
            " few well kept supplies."
               "\n");
         leather=clone_object(ARMOUR+"studded.c");
         leather->move(this_object());
         helmet=clone_object(ARMOUR+"helmet.c");
         helmet->move(this_object());
         quarterstaff=clone_object(WEAPONS+"quarterstaff.c");
         quarterstaff->move(this_object());
         this_player()->add_property("GNOME_EQ",1);
// Taniwha Leave it out
         //this_player()->adjust_xp(2000);
         return 1;
      }
   }
   else
   {
      return 0;
   }
}
