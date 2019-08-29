// Minimap 2.3b.   (c) 1998 Spp .
// By Dagda
#include "/d/abarrach/path.h"
inherit "/d/abarrach/handler/base_abarrach.c";

void setup()
{
   habitacion(8);
   // Disponible para usar con sar
   add_clone("npcs",1);
   add_exit("noroeste",VALLE"c0001.c","road");
   add_exit("noreste" ,VALLE"c0003.c","road");
   add_exit("este"    ,VALLE"c0103.c","road");
}