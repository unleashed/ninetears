// Minimap 2.3b.   (c) 1998 Spp .
// By Dagda
#include "/d/abarrach/path.h"
inherit "/d/abarrach/handler/base_abarrach.c";

void setup()
{
   set_short("corta");
   set_long("larga.\n");
   add_clone("npcs",1);
   add_exit("noroeste",BTHURKUN"torre_cuatro2215.c","road");
   add_exit("este"    ,BTHURKUN"torre_cinco2317.c","road");
   add_exit("sur"     ,BTHURKUN"torre_cinco2416.c","road");
}