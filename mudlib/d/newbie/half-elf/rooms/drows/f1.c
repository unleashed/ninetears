//Ljen nov -96

inherit"/std/room";
#include "path.h"
object rat;
void setup()
{
  set_light(50);

  set_short("Drow tunnels");

  set_long("Suddenly you hit the wall. The tunnel ends here,"
	   " there is just a hard stonewall to the east."
           " After you have searched a while you can see that" 
           " the tunnel suddenly heads back west and southwest."
           " The sounds are still in the air, but a bit weaker now."
           " Your ears almost sighs with relief.. \n"); 

  add_clone(NPC+"rat.c", 1); 
 
  add_exit("west", DROWS+"e1.c", "path");

  add_exit("southwest", DROWS+"e2.c", "path");

  
}
