// Minimap 2.3b.   (c) 1998 Spp .
// By Dagda
#include "/d/abarrach/path.h"
inherit "/d/abarrach/handler/base_abarrach.c";

void setup()
{
   set_short("corta");
   set_long("larga.\n");
   add_clone("npcs",1);
   add_exit("noroeste",BTHURKUN"bosque0417.c","road");
   add_exit("este"    ,BTHURKUN"ent_cementerio0519.c","road");
   add_exit("sudoeste",BTHURKUN"bosque0617.c","road");
}