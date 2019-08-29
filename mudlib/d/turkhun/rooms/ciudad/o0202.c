// Minimap 2.3b.   (c) 1998 Spp .
// By Dagda
inherit "/d/turkhun/handler/base_ciudad.c";
#include "/d/turkhun/path.h"

void setup()
{
   // Disponible para usar con sar
   habitacion(3);
   //Espacio para un sar
   add_exit("noroeste",CIUDAD"o0101.c","corridor");
   add_exit("noreste" ,CIUDAD"o0103.c","corridor");
   add_exit("este"    ,CIUDAD"o0203.c","corridor");
   add_exit("sudoeste",CIUDAD"f0301.c","corridor");
}