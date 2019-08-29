// Minimap 2.3b.   (c) 1998 Spp .
// By Dagda
//
inherit "/d/turkhun/handler/base_ciudad.c";
#include "/d/turkhun/path.h"

void setup()
{
   // Disponible para usar con sar
   habitacion(0);
   //Espacio para un sar
   add_exit("este"    ,CIUDAD"m0001.c","corridor");
   add_exit("sur"     ,CIUDAD"m0100.c","corridor");
   add_exit("sudeste" ,CIUDAD"o0101.c","corridor");
   add_exit("noroeste" ,VALLE"v0922.c","corridor");
}
