// Minimap 2.3b.   (c) 1998 Spp .
// By Dagda
#include "/d/abarrach/path.h"
inherit "/d/abarrach/handler/base_abarrach.c";

void setup()
{
   habitacion(8);
   // Disponible para usar con sar
   add_clone("npcs",1);
   add_exit("noreste" ,VALLE"c0209.c","road");
   add_exit("oeste"   ,VALLE"c0307.c","road");
   add_exit("sudeste" ,VALLE"c0409.c","road");
}