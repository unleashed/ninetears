// Minimap 2.3b.   (c) 1998 Spp .
// By Dagda
inherit "/d/turkhun/handler/base_ciudad.c";
#include "/d/turkhun/path.h"

void setup()
{
   // Disponible para usar con sar
   habitacion(3);
   //Espacio para un sar
   add_exit("noroeste",CIUDAD"f0507.c","corridor");
   add_exit("oeste"   ,CIUDAD"f0607.c","corridor");
   add_exit("noreste"   ,VARIOS"herreria.c","door");
}