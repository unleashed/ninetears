// Minimap 2.3b.   (c) 1998 Spp .
// By Dagda
inherit "/d/turkhun/handler/base_ciudad.c";
#include "/d/turkhun/path.h"

void setup()
{
   // Disponible para usar con sar
   habitacion(6);
   //Espacio para un sar
   add_exit("noreste" ,CIUDAD"n0710.c","corridor");
   add_exit("sudeste" ,CIUDAD"n0910.c","corridor");
}