inherit "/std/outside";
#include "path.h"

void setup ()   {
set_short("Macedonia:  Shadow Valley");
set_light(40);
   set_long("Macedonia:  Shadow Valley\n\n"
            "   Obvious directions are starting to fade out due to "
            "lack of travel along this path.  To the north there is "
            "a beautiful overlook of a large lake, but since you are "
            "not sure about your ability to swim, you do not dare "
            "enter it.  From the woodland area to the south, you can "
            "hear sounds of various creatures.  These sounds are "
            "starting to lure you to adventure into the looming "
           "trees and dense brush.  "
           "\n\n");
add_item("path","This is a narrow dirt path that runs through the "
          "grass alongside the lake.\n");
add_item(({"overlook","lake"}),"You are standing on spot north of "
           "the woods that give a perfect overlook of Lake "
           "Chicamocomico.  Looking at the calmness of the lake "
           "you feel more calm about the violence that is likly "
            "to face you in the future.\n");
add_item(({"woodland area","area","woods"}),"This area is overgrown "
           "with various trees and shrubs.  You are worried by the "
           "sounds, but your curiosity is growing faster than your "
           "fear.\n");
add_item(({"trees","looming trees"}),"These are very large trees "
           "which provide more than enough shade for the entire " 
           "forest.  Made up of mostly oak and maple, this would "
           "make an excellent place to find lumber to build a "
           "home, but you notice no stumps that have be left "
           "behind.\n");
add_item(({"brush","dense brush"}),"This brush is just the average "
           "wild shrubs found in most forest areas.  Since the "
           "light here is so scarce, there are no blooms growing "
           "here.\n");
add_clone(NPC+"frog.c",3);
add_exit("south",VALLEY +"gnome04","path");
add_exit("west",VALLEY +"gnome01","path");
add_exit("southeast",VALLEY +"gnome05","path");
}
