// Minimap 2.3b.   (c) 1998 Spp .
// By Dagda
#include "/d/abarrach/path.h"
inherit "/d/abarrach/handler/base_abarrach.c";

void setup()
{
   set_short("corta");
   set_long("larga.\n");
   add_clone("npcs",1);
   add_exit("norte"   ,BTHURKUN"torre_cuatro2515.c","road");
   add_exit("este"    ,BTHURKUN"torre_cuatro2616.c","road");
   add_exit("sudoeste",BTHURKUN"torre_tres2714.c","road");
}