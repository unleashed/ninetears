// Minimap 2.3b.   (c) 1998 Spp .
// By Dagda
#include "/d/abarrach/path.h"
inherit "/d/abarrach/handler/base_marisma.c";

void setup()
{
   set_short("corta");
   set_long("larga.\n");
   add_clone("npcs",1);
   add_exit("norte"   ,BTHURKUN"marisma2028.c","road");
   add_exit("oeste"   ,BTHURKUN"marisma2127.c","road");
   add_exit("este"    ,BTHURKUN"marisma2129.c","road");
}