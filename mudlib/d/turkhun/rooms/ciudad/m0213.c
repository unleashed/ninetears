// Minimap 2.3b.   (c) 1998 Spp .
// By Dagda
inherit "/d/turkhun/handler/base_ciudad.c";
#include "/d/turkhun/path.h"

void setup()
{
   // Disponible para usar con sar
   habitacion(1);
   //Espacio para un sar
   add_exit("noreste" ,CIUDAD"m0114.c","corridor");
   add_exit("oeste"   ,CIUDAD"m0212.c","corridor");
}