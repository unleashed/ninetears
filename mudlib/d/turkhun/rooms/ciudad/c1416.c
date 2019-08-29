// Minimap 2.3b.   (c) 1998 Spp .
// By Dagda
inherit "/d/turkhun/handler/base_ciudad.c";
#include "/d/turkhun/path.h"

void setup()
{
   // Disponible para usar con sar
   habitacion(7);
   //Espacio para un sar
   add_exit("norte"   ,CIUDAD"c1316.c","corridor");
   add_exit("noreste" ,CIUDAD"c1317.c","corridor");
   add_exit("sudoeste",CIUDAD"c1515.c","corridor");
}