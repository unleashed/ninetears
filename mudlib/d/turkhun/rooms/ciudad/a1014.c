// Minimap 2.3b.   (c) 1998 Spp .
// By Dagda
inherit "/d/turkhun/handler/base_ciudad.c";
#include "/d/turkhun/path.h"

void setup()
{
   // Disponible para usar con sar
   habitacion(4);
   //Espacio para un sar
   add_exit("norte"   ,CIUDAD"a0914.c","corridor");
   add_exit("noreste" ,CIUDAD"a0915.c","corridor");
   add_exit("sudeste" ,CIUDAD"a1115.c","corridor");
}