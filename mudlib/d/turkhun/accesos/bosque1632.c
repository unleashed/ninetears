// Minimap 2.3b.   (c) 1998 Spp .
// By Dagda
#include "/d/abarrach/path.h"
inherit "/d/abarrach/handler/base_abarrach.c";

void setup()
{
   set_short("corta");
   set_long("larga.\n");
   add_clone("npcs",1);
   add_exit("noroeste",BTHURKUN"bosque1531.c","road");
   add_exit("oeste"   ,BTHURKUN"bosque1631.c","road");
   add_exit("sur"     ,BTHURKUN"bosque1732.c","road");
}