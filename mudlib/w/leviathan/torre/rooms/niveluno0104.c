// Minimap 2.3b.   (c) 1998 Spp .
// By Pepito Destino=ROOMS
#include "../path.h"
inherit "/std/room.c";

void setup()
{
   set_short("Camino del Bosque (*)");
   set_long("Estas delante de uno de los mar inmensos bosques de bla "
        "bla...\n");
   set_light(50);
   add_item("Casa","Es una casa enorme... y tal y cual");
   add_exit("norte"   ,"/w/leviathan/torre/rooms/niveluno0004.c","road");
   add_exit("sur"     ,"/w/leviathan/torre/rooms/niveluno0204.c","road");
}