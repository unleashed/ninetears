// Minimap 2.3b.   (c) 1998 Spp .
// By Dagda
inherit "/d/turkhun/handler/base_ciudad.c";
#include "/d/turkhun/path.h"

void setup()
{
   // Disponible para usar con sar
   habitacion(5);
   //Espacio para un sar
   add_exit("norte"   ,CIUDAD"l1010.c","corridor");
   add_exit("sudeste" ,CIUDAD"l1211.c","corridor");
}