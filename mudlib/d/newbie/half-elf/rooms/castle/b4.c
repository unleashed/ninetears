/* Made by Ljen, nov - 1996 */

#include "path.h"

inherit "/std/room";

object servant;

void setup()
{

  set_short("Castle of the Green Sun: Dining room.");

  set_light(55);

  set_long("  This is the dining room of the castle, with the kitchen further"
           " west, and the library to the north. This is one of the few"
           " rooms that are lit enough. A big table stands in the middle"
           " of the room, with several chairs spread around it."
           " A blood red carpet covers most of the floor, giving the room"
           " a faint red glow. The perfect atmosphere for a meal...\n");

  add_item("chair", "Big and simple chairs, probably to make sure noone"
	   " would fall asleep during meetings.\n");

  add_item("drawings", " The drawings seems to be a very old language where"   
           "  you can understand some of the words: "
           " '.... Mirror ..exit.... treasure....  pull.'\n");

  add_item("carpet", "A red carpet with golden drawings.  The drawings"
            "seem to be a very old language where you can understand some"
            "words: '.... Mirror ..exit.... treasure....  pull.'\n");

 
  add_item("table", "A huge mahogny table, with markings from several"
           " warparties. It has definetely seen better days..\n");

  add_exit("west", CAST + "a4.c");
  add_exit("north", CAST+"b3.c");
  add_exit("south", CAST+"b5.c");
  add_exit("east", CAST+"c4.c");
  
}


void reset()
{
    if (!servant) 
    {
           
      servant = clone_object("/d/newbie/half-elf/npcs/servant.c");
      servant->move(this_object());
    }
}

void dest_me()
{
 
  if (servant)servant->dest_me();

  ::dest_me();

}    


