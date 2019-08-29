// Minimap 2.3b.   (c) 1998 Spp .
// By Dagda
#include "/d/abarrach/path.h"
inherit "/d/abarrach/handler/base_abarrach.c";

void setup()
{
   set_short("corta");
   set_long("larga.\n");
   add_clone("npcs",1);
   add_exit("noroeste",BTHURKUN"bosque2329.c","road");
   add_exit("noreste" ,BTHURKUN"bosque2331.c","road");
   add_exit("este"    ,BTHURKUN"bosque2431.c","road");
   add_exit("sudoeste",BTHURKUN"bosque2529.c","road");
}