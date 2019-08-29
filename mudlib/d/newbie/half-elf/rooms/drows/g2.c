//Ljen nov -96

inherit"/std/room";
#include "path.h"
object drow, rat;

void setup()
{
   set_light(50);

   set_short("Drow tunnel");

   set_long(" The narrow tunnel continues, but the sound is getting"
	    " louder and louder. Here you can also see traces of a kinda"
	    " camp. But there is also various instruments for torturing"
	    " people... You are starting to wonder what this is all about,"
	    " with the sound and now the instruments.. But it seems like"
	    " you have come too late.. The drows in here look like they"
	    " are pretty satisfied with whatever they have done."
	    " But they definately don't like that you have come here"
            " to disturb them! \n");


   add_item("wall", "You can't see much, but it seems like they are of"
            " some kind of black rock. Water is dripping slowly down.\n");

   add_item("instrument", " Various items for causing others pain."
	    " They seem well-used.. Full of bloodstains and gruesome"	
     	    " you would rather not touch them. \n");


   add_clone(NPC+"drow.c", 2);

   add_clone(NPC+"rat.c", 1);
 
   add_exit("southwest", DROWS+"f3.c", "path");

   add_exit("east", DROWS+"h2.c", "path");


}

