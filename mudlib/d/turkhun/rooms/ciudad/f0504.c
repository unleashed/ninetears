// Minimap 2.3b.   (c) 1998 Spp .
// By Dagda
inherit "/d/turkhun/handler/base_ciudad.c";
#include "/d/turkhun/path.h"

void setup()
{
   // Disponible para usar con sar
   habitacion(3);
   //Espacio para un sar
   add_exit("norte"   ,CIUDAD"f0404.c","corridor");
   add_exit("oeste"   ,CIUDAD"f0503.c","corridor");
   add_exit("este"    ,CIUDAD"f0505.c","corridor");
   add_exit("sur"     ,CIUDAD"f0604.c","corridor");
}