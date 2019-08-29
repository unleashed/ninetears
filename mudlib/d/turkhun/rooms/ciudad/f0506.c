// Minimap 2.3b.   (c) 1998 Spp .
// By Dagda
inherit "/d/turkhun/handler/base_ciudad.c";
#include "/d/turkhun/path.h"

void setup()
{
   // Disponible para usar con sar
   habitacion(3);
   //Espacio para un sar
   add_exit("norte"   ,CIUDAD"f0406.c","corridor");
   add_exit("oeste"   ,CIUDAD"f0505.c","corridor");
   add_exit("este"    ,CIUDAD"f0507.c","corridor");
   add_exit("sudoeste",CIUDAD"f0605.c","corridor");
   add_exit("sur"     ,CIUDAD"f0606.c","corridor");
}