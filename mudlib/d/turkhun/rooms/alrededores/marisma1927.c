// Minimap 2.3b.   (c) 1998 Spp .
// By Dagda
#include "/d/abarrach/path.h"
inherit "/d/abarrach/handler/base_marisma.c";

void setup()
{
   set_short("corta");
   set_long("larga.\n");
   add_clone("npcs",1);
   add_exit("noroeste",BTHURKUN"marisma1826.c","road");
   add_exit("norte"   ,BTHURKUN"marisma1827.c","road");
   add_exit("sudoeste",BTHURKUN"marisma2026.c","road");
}