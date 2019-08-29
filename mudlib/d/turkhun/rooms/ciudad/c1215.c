// Minimap 2.3b.   (c) 1998 Spp .
// By Dagda
inherit "/d/turkhun/handler/base_ciudad.c";
#include "/d/turkhun/path.h"

void setup()
{
   // Disponible para usar con sar
   habitacion(7);
   //Espacio para un sar
   add_exit("noreste" ,CIUDAD"c1116.c","corridor");
   add_exit("oeste"   ,CIUDAD"c1214.c","corridor");
}