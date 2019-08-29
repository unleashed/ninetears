// Minimap 2.3b.   (c) 1998 Spp .
// By Dagda
#include "/d/abarrach/path.h"
inherit "/d/abarrach/handler/base_abarrach.c";

void setup()
{
   habitacion(8);
   // Disponible para usar con sar
   add_clone("npcs",1);
   add_exit("noreste" ,VALLE"b1814.c","road");
   add_exit("oeste"   ,VALLE"b1912.c","road");
   add_exit("sudeste" ,VALLE"b2014.c","road");
}