// Minimap 2.3b.   (c) 1998 Spp .
// By Dagda
inherit "/d/turkhun/handler/base_ciudad.c";
#include "/d/turkhun/path.h"

void setup()
{
   // Disponible para usar con sar
   habitacion(7);
   //Espacio para un sar
   add_exit("norte"   ,CIUDAD"c1116.c","corridor");
   add_exit("sudeste" ,CIUDAD"c1317.c","corridor");
}