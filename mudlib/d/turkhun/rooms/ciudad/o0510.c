// Minimap 2.3b.   (c) 1998 Spp .
// By Dagda
inherit "/d/turkhun/handler/base_ciudad.c";
#include "/d/turkhun/path.h"

void setup()
{
   // Disponible para usar con sar
   habitacion(3);
   //Espacio para un sar
   add_exit("norte"   ,CIUDAD"o0410.c","corridor");
   add_exit("sudoeste",CIUDAD"n0609.c","corridor");
   add_exit("sudeste" ,CIUDAD"o0611.c","corridor");
}