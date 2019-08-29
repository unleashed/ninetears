// Minimap 2.3b.   (c) 1998 Spp .
// By Dagda
#include "/d/abarrach/path.h"
inherit "/d/abarrach/handler/base_abarrach.c";

void setup()
{
   habitacion(8);
   // Disponible para usar con sar
   add_clone("npcs",1);
   add_exit("noreste" ,VALLE"b0531.c","road");
   add_exit("oeste"   ,VALLE"b0629.c","road");
   add_exit("sudoeste",VALLE"b0729.c","road");
   add_exit("sur"     ,VALLE"b0730.c","road");
}