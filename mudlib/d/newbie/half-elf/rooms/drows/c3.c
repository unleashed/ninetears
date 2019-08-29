//Ljen nov -96

inherit"/std/room";
#include "path.h"
object rat;
void setup()
{
  set_light(50);

  set_short("Drow tunnels");

  set_long("The dark decends upon you as a cloak, creating a dark and"
	   " fearful feeling. This place is _really_ creepy!"
	   " You can feel a weak wind stroking your face, but it also"
           " brings with it moans and faint screams as of a tortured soul"
	   " destined to live in pain forever.. That sound could make"
           " a poor half-elf go crazy. The tunnels continues west and"
	   " east from here. \n");

  add_clone(NPC"rat.c", 1);

  add_exit("east", DROWS+"d3.c", "path");

  add_exit("west", DROWS+"b3.c", "path");

}
