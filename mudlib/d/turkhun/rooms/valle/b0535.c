// Minimap 2.3b.   (c) 1998 Spp .
// By Dagda
#include "/d/abarrach/path.h"
inherit "/d/abarrach/handler/base_abarrach.c";

void setup()
{
   habitacion(8);
   // Disponible para usar con sar
   add_clone("npcs",1);
   add_exit("norte"   ,VALLE"b0435.c","road");
   add_exit("oeste"   ,VALLE"b0534.c","road");
   add_exit("sur"     ,VALLE"b0635.c","road");
}