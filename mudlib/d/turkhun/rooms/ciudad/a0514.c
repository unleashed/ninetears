// Minimap 2.3b.   (c) 1998 Spp .
// By Dagda
inherit "/d/turkhun/handler/base_ciudad.c";
#include "/d/turkhun/path.h"

void setup()
{
   // Disponible para usar con sar
   habitacion(4);
   //Espacio para un sar
   add_exit("noroeste",CIUDAD"a0413.c","corridor");
   add_exit("noreste" ,CIUDAD"a0415.c","corridor");
   add_exit("sudeste" ,CIUDAD"a0615.c","corridor");
}