// Minimap 2.3b.   (c) 1998 Spp .
// By Dagda
inherit "/d/turkhun/handler/base_ciudad.c";
#include "/d/turkhun/path.h"

void setup()
{
   // Disponible para usar con sar
   habitacion(4);
   //Espacio para un sar
   add_exit("noreste" ,CIUDAD"a0715.c","corridor");
   add_exit("oeste"   ,CIUDAD"a0813.c","corridor");
   add_exit("sur"     ,CIUDAD"a0914.c","corridor");
}