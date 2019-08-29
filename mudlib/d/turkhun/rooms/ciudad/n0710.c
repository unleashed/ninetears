// Minimap 2.3b.   (c) 1998 Spp .
// By Dagda
inherit "/d/turkhun/handler/base_ciudad.c";
#include "/d/turkhun/path.h"

void setup()
{
   // Disponible para usar con sar
   habitacion(6);
   //Espacio para un sar
   add_exit("norte"   ,CIUDAD"n0610.c","corridor");
   add_exit("oeste"   ,CIUDAD"n0709.c","corridor");
   add_exit("sudoeste",CIUDAD"n0809.c","corridor");
}