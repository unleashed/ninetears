// Minimap 2.3b.   (c) 1998 Spp .
// By Dagda
#include "/d/abarrach/path.h"
inherit "/d/abarrach/handler/base_abarrach.c";

void setup()
{
   set_short("corta");
   set_long("larga.\n");
   add_clone("npcs",1);
   add_exit("noroeste",BTHURKUN"torre_dos2013.c","road");
   add_exit("este"    ,BTHURKUN"torre_tres2115.c","road");
   add_exit("sur"     ,BTHURKUN"torre_tres2214.c","road");
}