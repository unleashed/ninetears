// Minimap 2.3b.   (c) 1998 Spp .
// By Dagda
#include "/d/abarrach/path.h"
inherit "/d/abarrach/handler/base_abarrach.c";

void setup()
{
   set_short("corta");
   set_long("larga.\n");
   add_clone("npcs",1);
   add_exit("norte"   ,BTHURKUN"torre_cinco2420.c","road");
   add_exit("oeste"   ,BTHURKUN"torre_cinco2519.c","road");
   add_exit("sudeste" ,BTHURKUN"torre_cuatro2621.c","road");
}