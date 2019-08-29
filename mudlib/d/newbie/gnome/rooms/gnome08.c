inherit "/std/room";
#include "path.h"

void setup ()   {
set_short("Macedonia:  Town Hall");
set_light(40);
set_long("Macedonia:  Town Hall\n\n"
         "   This is a fairly well decorated room.  Hanging on "
         "the northern wall, there is a large map of the realms.  "
         "On the east wall there hangs a beautifully painted "
         "portrait of Aldinanachru, one of the most heroic citizens "
         "in the entire history of Macedonia.  In the direct "
         "center of the room, there is a large oak table "
         "surrounded by a dozen chairs.  Above this table, there "
         "is a large chandelier that is used for the special "
         "gatherings of all the citizens.  But for normal "
         "discussions, the torches on each wall provide ample "
         "lighting.  The strangest structure about this town hall "
         "is the set of stairs leading to a second story of "
         "this building."
         "\n\n");
  //added by Christian oct 28//
add_item("stairs","These stairs lead up, to the second story.\n");
add_exit("southwest",VALLEY +"gnome14","path");
add_exit("up","/d/newbie/gnome/rooms/enter.c","door");
}
void init()
{
   ::init();
   add_action("unlock_me","unlock");
   add_action("go_up","u*p");
}
int unlock_me(string str)
{
   object *stuff;
   int d;
   int c;
   if(str == "door with key")
   {
      stuff = all_inventory(this_player());
      for(c=0; c < sizeof(stuff);c++)
      {
         if((string)stuff[c]->query_name() == "key")
         {
            ++d;
            write("You unlock the door at the top of the stairs.\n");
            this_player()->add_property("GNOME_UNLOCK",1);
            return 1;
         }
      }
   }
   else
   {
      return 0;
   }
}
int go_up()
{
   if(this_player()->query_property("GNOME_UNLOCK"))
   {
      write("You climb the stairs and open the door to see...\n\n");
      this_player()->move(VALLEY+"enter.c");
      this_player()->look_me();
      return 1;
   }
   else
   {
      write("You cannot seem to budge this tightly locked door.\n");
      return 1;
   }
}
