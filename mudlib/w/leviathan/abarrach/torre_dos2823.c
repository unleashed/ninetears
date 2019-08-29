// Minimap 2.3b.   (c) 1998 Spp .
// By Dagda
#include "/d/abarrach/path.h"
inherit "/d/abarrach/handler/base_abarrach.c";

void setup()
{
   set_short("corta");
   set_long("larga.\n");
   add_clone("npcs",1);
   add_exit("noroeste",BTHURKUN"torre_tres2722.c","road");
   add_exit("norte"   ,BTHURKUN"torre_dos2723.c","road");
   add_exit("oeste"   ,BTHURKUN"torre_dos2822.c","road");
}