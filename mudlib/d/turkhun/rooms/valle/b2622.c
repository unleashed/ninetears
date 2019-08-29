// Minimap 2.3b.   (c) 1998 Spp .
// By Dagda
#include "/d/abarrach/path.h"
inherit "/d/abarrach/handler/base_abarrach.c";

void setup()
{
   habitacion(8);
   // Disponible para usar con sar
   add_clone("npcs",1);
   add_exit("este"    ,VALLE"b2623.c","road");
   add_exit("sudoeste",VALLE"b2721.c","road");
   add_exit("sudeste" ,VALLE"b2723.c","road");
}