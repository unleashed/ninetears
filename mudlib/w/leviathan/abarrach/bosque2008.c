// Minimap 2.3b.   (c) 1998 Spp .
// By Dagda
#include "/d/abarrach/path.h"
inherit "/d/abarrach/handler/base_abarrach.c";

void setup()
{
   set_short("corta");
   set_long("larga.\n");
   add_clone("npcs",1);
   add_exit("norte"   ,BTHURKUN"bosque1908.c","road");
   add_exit("este"    ,BTHURKUN"bosque2009.c","road");
   add_exit("sudoeste",BTHURKUN"bosque2107.c","road");
}