// Minimap 2.3b.   (c) 1998 Spp .
// By Dagda
inherit "/d/turkhun/handler/base_ciudad.c";
#include "/d/turkhun/path.h"

void setup()
{
   // Disponible para usar con sar
   habitacion(3);
   //Espacio para un sar
   add_exit("noroeste",CIUDAD"o0711.c","corridor");
   add_exit("sudoeste",CIUDAD"l0911.c","corridor");
   add_exit("sudeste" ,CIUDAD"c0913.c","corridor");
}