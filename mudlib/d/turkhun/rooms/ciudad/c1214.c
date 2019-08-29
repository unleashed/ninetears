// Minimap 2.3b.   (c) 1998 Spp .
// By Dagda
inherit "/d/turkhun/handler/base_ciudad.c";
#include "/d/turkhun/path.h"

void setup()
{
   // Disponible para usar con sar
   habitacion(7);
   //Espacio para un sar
   add_exit("noroeste",CIUDAD"c1113.c","corridor");
   add_exit("este"    ,CIUDAD"c1215.c","corridor");
   add_exit("sur"     ,CIUDAD"c1314.c","corridor");
   add_exit("sudeste" ,CIUDAD"c1315.c","corridor");
}