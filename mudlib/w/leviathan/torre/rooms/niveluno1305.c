// Minimap 2.3b.   (c) 1998 Spp .
// By Pepito
#include "../path.h"
inherit "/std/room.c";

void setup()
{
   set_short("Camino del Bosque (*)");
   set_long("Estas delante de uno de los mar inmensos bosques de bla "
        "bla...\n");
   set_light(50);
   add_item("Casa","Es una casa enorme... y tal y cual");
   add_exit("oeste"   ,"/w/leviathan/torre/niveluno1304.c","road");
   add_exit("este"    ,"/w/leviathan/torre/niveluno1306.c","road");
}