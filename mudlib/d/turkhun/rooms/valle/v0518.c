// Minimap 2.3b.   (c) 1998 Spp .
// By Dagda
#include "/d/abarrach/path.h"
inherit "/d/abarrach/handler/base_abarrach.c";

void setup()
{
   habitacion(8);
   // Disponible para usar con sar
   add_clone("npcs",1);
   add_exit("noreste" ,VALLE"v0419.c","road");
   add_exit("oeste"   ,VALLE"v0517.c","road");
   add_exit("sudoeste",VALLE"v0617.c","road");
}