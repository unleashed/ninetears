// Minimap 2.3b.   (c) 1998 Spp .
// By Dagda
inherit "/d/turkhun/handler/base_ciudad.c";
#include "/d/turkhun/path.h"

void setup()
{
   // Disponible para usar con sar
   habitacion(7);
   //Espacio para un sar
   add_exit("noroeste",CIUDAD"c1216.c","corridor");
   add_exit("este"    ,CIUDAD"c1318.c","corridor");
   add_exit("sudoeste",CIUDAD"c1416.c","corridor");
   add_exit("sudeste" ,CIUDAD"c1418.c","corridor");
}