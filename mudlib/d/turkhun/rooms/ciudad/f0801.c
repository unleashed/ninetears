// Minimap 2.3b.   (c) 1998 Spp .
// By Dagda
inherit "/d/turkhun/handler/base_ciudad.c";
#include "/d/turkhun/path.h"

void setup()
{
   // Disponible para usar con sar
   habitacion(3);
   //Espacio para un sar
   add_exit("noreste" ,CIUDAD"f0702.c","corridor");
   add_exit("este"    ,CIUDAD"f0802.c","corridor");
   add_exit("norte"    ,VARIOS"tienda.c","corridor");
}