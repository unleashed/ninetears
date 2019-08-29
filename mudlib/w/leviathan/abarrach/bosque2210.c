// Minimap 2.3b.   (c) 1998 Spp .
// By Dagda
#include "/d/abarrach/path.h"
inherit "/d/abarrach/handler/base_abarrach.c";

void setup()
{
   set_short("corta");
   set_long("larga.\n");
   add_clone("npcs",1);
   add_exit("norte"   ,BTHURKUN"bosque2110.c","road");
   add_exit("oeste"   ,BTHURKUN"bosque2209.c","road");
   add_exit("sudoeste",BTHURKUN"bosque2309.c","road");
   add_exit("sudeste" ,BTHURKUN"bosque2311.c","road");
}