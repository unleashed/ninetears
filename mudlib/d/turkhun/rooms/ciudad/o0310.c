// Minimap 2.3b.   (c) 1998 Spp .
// By Dagda
inherit "/d/turkhun/handler/base_ciudad.c";
#include "/d/turkhun/path.h"

void setup()
{
   // Disponible para usar con sar
   habitacion(3);
   //Espacio para un sar
   add_exit("oeste"   ,CIUDAD"o0309.c","corridor");
   add_exit("este"    ,CIUDAD"a0311.c","corridor");
   add_exit("sur"     ,CIUDAD"o0410.c","corridor");
}