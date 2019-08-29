// Minimap 2.3b.   (c) 1998 Spp .
// By Dagda
inherit "/d/turkhun/handler/base_ciudad.c";
#include "/d/turkhun/path.h"

void setup()
{
   // Disponible para usar con sar
   habitacion(6);
   //Espacio para un sar
   add_exit("noroeste",CIUDAD"n0808.c","corridor");
   add_exit("este"    ,CIUDAD"n0910.c","corridor");
   add_exit("sudoeste",CIUDAD"n1008.c","corridor");
}