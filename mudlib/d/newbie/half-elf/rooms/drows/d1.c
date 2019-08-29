//Ljen nov -96

inherit"/std/room";
#include "path.h"
object rat;
void setup()
{
  set_light(50);

  set_short("Drow tunnels");

  set_long("The tunnel heads east into the darkness. You can't see much"
           " here, you can barely make out your feet at the floor."
           " But you can hear... rats muffling around, faint screams"
	   " coming from the east.. It sounds like a tortured soul"
           " crying desperately for help and mercy. The very sound"
           " gives you the creep, and your feet seems to want to leave"
           " this place.\n");

  add_clone(NPC+"rat.c", 1); 
 
  add_exit("east", DROWS+"e1.c", "path");

  add_exit("west", DROWS+"c1.c", "path");

  add_exit("southwest", DROWS+"c2.c", "path");

  
}
