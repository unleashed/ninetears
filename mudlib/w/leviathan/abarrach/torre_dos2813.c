// Minimap 2.3b.   (c) 1998 Spp .
// By Dagda
#include "/d/abarrach/path.h"
inherit "/d/abarrach/handler/base_abarrach.c";

void setup()
{
   set_short("corta");
   set_long("larga.\n");
   add_clone("npcs",1);
   add_exit("norte"   ,BTHURKUN"torre_dos2713.c","road");
   add_exit("este"    ,BTHURKUN"torre_dos2814.c","road");
   add_exit("sudoeste",BTHURKUN"torre_uno2912.c","road");
}