//Ljen nov -96

inherit"/std/room";
#include "path.h"
object rat;
void setup()
{
  set_light(50);

  set_short("Drow tunnels");

  set_long("As far as you can see, the tunnel does a bend here, turning"
           " east. It is very dark, but somehow there is something in here"
           " giving a small amount of light. Seems to be a kind of moss."
           " The sound of water dripping will surely make you crazy soon.."
           " It is everywhere! Perhaps you should get out of here.. \n");

  add_clone(NPC"rat.c", 1);

  add_exit("east", DROWS+"c3.c", "path");

  add_exit("north", DROWS+"b2.c", "path");

}
