// Minimap 2.3b.   (c) 1998 Spp .
// By Dagda
#include "/d/abarrach/path.h"
inherit "/d/abarrach/handler/base_abarrach.c";

void setup()
{
   set_short("corta");
   set_long("larga.\n");
   add_clone("npcs",1);
   add_exit("norte"   ,BTHURKUN"tumba0627.c","road");
   add_exit("oeste"   ,BTHURKUN"pasillo0726.c","road");
   add_exit("este"    ,BTHURKUN"cementerio0728.c","road");
}