// Minimap 2.3b.   (c) 1998 Spp .
// By Dagda
inherit "/d/turkhun/handler/base_ciudad.c";
#include "/d/turkhun/path.h"

void setup()
{
   // Disponible para usar con sar
   habitacion(3);
   //Espacio para un sar
   add_exit("este"    ,CIUDAD"o0208.c","corridor");
   add_exit("sur"     ,CIUDAD"f0307.c","corridor");
   add_exit("sudeste" ,CIUDAD"o0308.c","corridor");
}