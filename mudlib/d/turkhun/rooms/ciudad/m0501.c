// Minimap 2.3b.   (c) 1998 Spp .
// By Dagda
inherit "/d/turkhun/handler/base_ciudad.c";
#include "/d/turkhun/path.h"

void setup()
{
   // Disponible para usar con sar
   habitacion(1);
   //Espacio para un sar
   add_exit("noroeste",CIUDAD"m0400.c","corridor");
   add_exit("sur"     ,CIUDAD"m0601.c","corridor");
}