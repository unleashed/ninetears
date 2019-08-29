// Minimap 2.3b.   (c) 1998 Spp .
// By Dagda
#include "/d/abarrach/path.h"
inherit "/d/abarrach/handler/base_abarrach.c";

void setup()
{
   habitacion(8);
   // Disponible para usar con sar
   add_clone("npcs",1);
   add_exit("noroeste",VALLE"b2522.c","road");
   add_exit("oeste"   ,VALLE"b2622.c","road");
   add_exit("este"    ,VALLE"b2624.c","road");
}