// Minimap 2.3b.   (c) 1998 Spp .
// By Dagda
#include "/d/abarrach/path.h"
inherit "/d/abarrach/handler/base_abarrach.c";

void setup()
{
   set_short("corta");
   set_long("larga.\n");
   add_clone("npcs",1);
   add_exit("oeste"   ,BTHURKUN"torre_tres2121.c","road");
   add_exit("sudoeste",BTHURKUN"torre_cuatro2221.c","road");
   add_exit("sur"     ,BTHURKUN"torre_tres2222.c","road");
}