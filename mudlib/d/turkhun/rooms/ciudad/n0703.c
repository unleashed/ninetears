// Minimap 2.3b.   (c) 1998 Spp .
// By Dagda
inherit "/d/turkhun/handler/base_ciudad.c";
#include "/d/turkhun/path.h"

void setup()
{
   // Disponible para usar con sar
   habitacion(6);
   //Espacio para un sar
   add_exit("este"    ,CIUDAD"n0704.c","corridor");
   add_exit("sur"     ,CIUDAD"n0803.c","corridor");
}