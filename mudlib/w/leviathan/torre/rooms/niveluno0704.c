// Minimap 2.3b.   (c) 1998 Spp .
// By Pepito
#include "../path.h"
inherit "/std/room.c";

void setup()
{
   set_short("Camino oculto en el Bosque");
   set_long("Estas delante de uno de los mar inmensos bosques de bla "
        "bla...\n");
   set_light(50);
   add_item("Casa","Es una casa enorme... y tal y cual");
   add_exit("noroeste","/w/leviathan/torre/niveluno0603.c","road");
   add_exit("sudoeste","/w/leviathan/torre/niveluno0803.c","road");
}