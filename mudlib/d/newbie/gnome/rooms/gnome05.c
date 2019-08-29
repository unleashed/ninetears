inherit "/std/outside";
#include "path.h"

void setup ()   {
set_short("Macedonia:  Shadow Valley");
set_light(40);
   set_long("Macedonia:  Shadow Valley\n\n"
            "   This area is overgrown with weeds and brush. "
            "It is hard to believe that so many plants can grown "
            "here since the trees block so much of the sun that "
          "plants need to grow.  Oddly, there is a large "
            "boulder placed among the weeds to the southwest.  "
            "\n\n");
add_item(({"area","weeds","brush","plants"}),"The plants here are "
           "found growing all through the woods.  You just are "
           "amazed that these plants have grown so full due to "
           "the lack of sun in the area.\n");
add_item("trees","Ths trees here have grown to enormous heights.  "
         "Their growth has caused the forest to be cover with a "
         "refreshing shade.\n");
add_item("boulder","This is a rather large and oddly shaped "
         "boulder.  It looks like it might have been placed here "
         "for the citizens of Macedonia to sit in the peace and "
         "quiet of nature.\n");
add_clone(NPC+"snake.c",1);
add_clone(NPC+"owl.c",1);
add_clone(NPC+"frog.c",1);

add_exit("northwest",VALLEY +"gnome02","path");
add_exit("southeast",VALLEY +"gnome12","path");
add_property("no_undead",1);
}
