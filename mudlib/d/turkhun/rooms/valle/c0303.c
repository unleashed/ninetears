// Minimap 2.3b.   (c) 1998 Spp .
// By Dagda
#include "/d/abarrach/path.h"
inherit "/d/abarrach/handler/base_abarrach.c";

void setup()
{
   habitacion(8);
   // Disponible para usar con sar
   add_clone("npcs",1);
   add_exit("noreste" ,VALLE"c0204.c","road");
   add_exit("este"    ,VALLE"c0304.c","road");
   add_exit("sudoeste",VALLE"c0402.c","road");
}