// Minimap 2.3b.   (c) 1998 Spp .
// By Dagda
#include "/d/abarrach/path.h"
inherit "/d/abarrach/handler/base_marisma.c";

void setup()
{
   set_short("corta");
   set_long("larga.\n");
   add_clone("npcs",1);
   add_exit("norte"   ,BTHURKUN"marisma2328.c","road");
   add_exit("oeste"   ,BTHURKUN"marisma2427.c","road");
   add_exit("sudoeste",BTHURKUN"marisma2527.c","road");
}