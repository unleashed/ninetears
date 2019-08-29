inherit "/std/outside";
#include "path.h"

void setup ()   {
set_short("Macedonia:  Shadow Valley");
set_light(40);
set_long("Macedonia:  Shadow Valley\n\n"
            "   Deep into the Whispering Woods of Shadow "
            "Valley, there are many types of trees growing "
            "to enormous heights.  But in this particular "
            "spot, you notice a strange growth of beautiful "
            "flowers.  In the background of the flowers, there "
            "is a huge boulder which hinders movement to the northeast.  "
            "\n\n");
add_item("flowers","There are hundreds of colorful flowers growing "
         "around the huge boulder here.  Among them all you think "
         "you see a single white rose far in the background.\n");
add_item(({"rose","white rose"}),"Looking far to the back of "
            "the flowers, your eyes are drawn to a beautiful, "
            "white rose.  Its clean, white petals and long stem "
            "make it the best pick of the garden. \n");
add_item(({"spot","ground"}),"Despite the huge amount of shade "
           "here, the ground it covered with beautiful "
           "flowers.\n");
add_item("boulder","This is a rather large and oddly shaped "
         "boulder.  It looks like it might have been placed here "
         "for the citizens of Macedonia to sit in the peace and "
         "quiet of nature.\n");
add_item("trees","The trees here have grown to enormous heights.  "
         "Their growth has caused the forest to be covered with a "
         "refreshing shade.\n");
add_exit("east",VALLEY +"gnome11","path");
add_exit("northwest",VALLEY +"gnome03","path");
add_exit("southeast",VALLEY +"gnome17","path");
add_exit("southwest",VALLEY +"gnome16","path");
add_property("no_undead", 1);
}
void init()
{
   add_action("pick_me","pick");
   ::init();
}
int pick_me(string str)
{
   if(str == "rose" || str == "white rose")
      {
         if(this_player()->query_property("GNOME_ROSE") ||
            this_player()->query_property("GNOME_ROPE"))
            {
               write("As you reach for the white rose at the back "
		     "of the flowerbed, you realize that it was only "
		     "a large white butterfly perched atop a "
		     "daffodil.\n");
               return 1;
            }
         else
            {
               write("You reach to the back of the flowerbed and "
		      "carefully brake the stem and pull the rose "
		      "from the garden.\n");
	       clone_object(MISC+"rose.c")->move(this_player());
this_player()->add_timed_property("GNOME_ROSE",1,50);
                  return 1;
              }
          }
     else
      {
         return 0;
      }
}
