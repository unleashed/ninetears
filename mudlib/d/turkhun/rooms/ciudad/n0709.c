// Minimap 2.3b.   (c) 1998 Spp .
// By Dagda
inherit "/d/turkhun/handler/base_ciudad.c";
#include "/d/turkhun/path.h"

void setup()
{
   // Disponible para usar con sar
   habitacion(6);
   //Espacio para un sar
   add_exit("oeste"   ,CIUDAD"n0708.c","corridor");
   add_exit("este"    ,CIUDAD"n0710.c","corridor");
   add_exit("sudoeste",CIUDAD"n0808.c","corridor");
}