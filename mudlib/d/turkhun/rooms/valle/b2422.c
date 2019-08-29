// Minimap 2.3b.   (c) 1998 Spp .
// By Dagda
#include "/d/abarrach/path.h"
inherit "/d/abarrach/handler/base_abarrach.c";

void setup()
{
   habitacion(8);
   // Disponible para usar con sar
   add_clone("npcs",1);
   add_exit("norte"   ,VALLE"b2322.c","road");
   add_exit("este"    ,VALLE"b2423.c","road");
   add_exit("sur"     ,VALLE"b2522.c","road");
}