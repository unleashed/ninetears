inherit "std/room";
#include "path.h"
 
object priest;

void setup() {

   set_short("Garden");

   set_long(

"This is a lovely garden with many different types of flowers in it.  "+
"To the "+
"east is the courtyard.  \n");

   set_light(100);
   add_alias("flowers", "flower");
   add_item("flower",
"Clerics grow a wide variety of the "+
"flowers here in this garden.\n");
   add_item("variety",
"You see a rose bush, maybe as it gets close to summertime, you might be able "+
"to plant a flower in the garden.\n");
   add_item("bush",
"A heavily thorned rose bush with many flowers on it.\n");
   add_item("rose",
"You see several beautiful roses on the rose bush.\n");
   add_item("garden",
"You can feel the warmth of the sun beating down on you.  It helps you feel "+
"more at peace.  This garden looks like it can use more flowers in it.\n");
   add_exit("east", ROOM+"tymcourt" , "door");

}

 

 

void reset()
   {if(!priest)
      {priest=clone_object("/d/bf/banefall/mobs/tpriest.c");
     priest->move(this_object());
   }
   }

