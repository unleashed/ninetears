// Minimap 2.3b.   (c) 1998 Spp .
// By Dagda
#include "/d/abarrach/path.h"
inherit "/d/abarrach/handler/base_abarrach.c";

void setup()
{
   set_short("corta");
   set_long("larga.\n");
   add_clone("npcs",1);
   add_exit("noroeste",CIUDAD"a0211.c","road");
   add_exit("este"    ,CIUDAD"a0313.c","road");
   add_exit("sudoeste",CIUDAD"a0411.c","road");
}