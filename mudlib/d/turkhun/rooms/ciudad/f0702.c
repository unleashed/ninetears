// Minimap 2.3b.   (c) 1998 Spp .
// By Dagda
inherit "/d/turkhun/handler/base_ciudad.c";
#include "/d/turkhun/path.h"

void setup()
{
   // Disponible para usar con sar
   habitacion(3);
   //Espacio para un sar
   add_exit("norte"   ,CIUDAD"f0602.c","corridor");
   add_exit("noreste" ,CIUDAD"f0603.c","corridor");
   add_exit("sudoeste",CIUDAD"f0801.c","corridor");
   add_exit("sur"     ,CIUDAD"f0802.c","corridor");
}