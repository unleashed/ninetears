// Minimap 2.3b.   (c) 1998 Spp .
// By Pepito Destino=ROOMS
#include "../path.h"
inherit "/std/room.c";

void setup()
{
   set_short("Nivel 2 de la torre.");
   set_long("Estas en el segundo nivel de la torre.\n");
   set_light(50);
   add_item("Casa","Es una casa enorme... y tal y cual");
   add_exit("oeste"   ,"/w/leviathan/torre/rooms/niveldos1300.c","road");
   add_exit("este"    ,"/w/leviathan/torre/rooms/niveldos1302.c","road");
}