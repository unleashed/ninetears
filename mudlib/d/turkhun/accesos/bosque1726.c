// Minimap 2.3b.   (c) 1998 Spp .
// By Dagda
#include "/d/abarrach/path.h"
inherit "/d/abarrach/handler/base_abarrach.c";

void setup()
{
   set_short("corta");
   set_long("larga.\n");
   add_clone("npcs",1);
   add_exit("norte"   ,BTHURKUN"bosque1626.c","road");
   add_exit("oeste"   ,BTHURKUN"bosque1725.c","road");
   add_exit("este"    ,BTHURKUN"bosque1727.c","road");
   add_exit("sudeste" ,BTHURKUN"bosque1827.c","road");
}