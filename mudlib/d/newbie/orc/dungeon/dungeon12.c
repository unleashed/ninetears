#include "path.h"
inherit CASTLE+"baseroom.c";
int done;

void setup() { my_setup();
set_short("Realm of the Orc:  Dungeon Room");
set_light(40);
set_long("\n   Realm of the Orc:  Dungeon Room.\n\n"
         "     This is a poor place to live "
         "but no one lives here because they want to.  Next to "
         "the northern wall, there is a small cot.  Other than that "
         "you notice nothing that attracts any interest.\n\n");
   add_item("cot","   This is a small wooden cot that would normally "
            "be of no interest at all.  However, this one is "
            "because it is occupied by the skeletal remains of some "
            "poor creature.  \n");
   add_item(({"remains","creature","skeleton"}),"  The deceased "
        "creature looks to be a Dwarf of some high standing.  The "
        "clothes on the body seem to have a regal look to them.  "
        "There seems to be something clenched in the bony hand of this "
        "poor creature.\n");

   add_item(({"finger","hand"}),"What are left of the fingers of this "
       "bony hand seem to be clentching something.  "
       "You might be able to open the hand and get it.  "
       "\n\n");
add_exit("east",DUNGEON +"dungeon13","door");
}
void init()
{
add_action("do_open","open");
   ::init();
}
void reset()
{
::reset();
   done = 0;
}
int do_open(string str)
{
   if(str == "hand")
      {
         if(done)
           {
            write("   It would appear that someone has beaten you to "
                  "the crown, perhaps you should try later.\n");
            return 1;
           }

      if(!done)
         {
         done = 1;
         write("\nYou manage to pry a crown out of the "
               "skeletal hands.\n");
         clone_object(MISC+"crown.c")->move(this_player());
         this_player()->add_property("ORC_CROWN",1);
         return 1;
         }
         }
      else
      {
         return 0;
      }
}
