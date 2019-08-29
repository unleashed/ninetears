// Minimap 2.3b.   (c) 1998 Spp .
// By Dagda
inherit "/d/turkhun/handler/base_ciudad.c";
#include "/d/turkhun/path.h"

void setup()
{
   // Disponible para usar con sar
   habitacion(5);
   //Espacio para un sar
   add_exit("noroeste",CIUDAD"l1208.c","corridor");
   add_exit("norte"   ,CIUDAD"l1209.c","corridor");
   add_exit("sur"     ,CIUDAD"l1409.c","corridor");
}