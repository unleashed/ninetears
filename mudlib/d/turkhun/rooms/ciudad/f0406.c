// Minimap 2.3b.   (c) 1998 Spp .
// By Dagda
inherit "/d/turkhun/handler/base_ciudad.c";
#include "/d/turkhun/path.h"

void setup()
{
   // Disponible para usar con sar
   habitacion(3);
   //Espacio para un sar
   add_exit("norte"   ,CIUDAD"f0306.c","corridor");
   add_exit("oeste"   ,CIUDAD"f0405.c","corridor");
   add_exit("este"    ,CIUDAD"f0407.c","corridor");
   add_exit("sur"     ,CIUDAD"f0506.c","corridor");
}