// Minimap 2.3b.   (c) 1998 Spp .
// By Dagda
#include "/d/abarrach/path.h"
inherit "/d/abarrach/handler/base_abarrach.c";

void setup()
{
   set_short("corta");
   set_long("larga.\n");
   add_clone("npcs",1);
   add_exit("noroeste",BTHURKUN"bosque1817.c","road");
   add_exit("oeste"   ,BTHURKUN"torre_uno1917.c","road");
   add_exit("este"    ,BTHURKUN"torre_uno1919.c","road");
}