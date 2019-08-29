// Minimap 2.3b.   (c) 1998 Spp .
// By Dagda
#include "/d/abarrach/path.h"
inherit "/d/abarrach/handler/base_marisma.c";

void setup()
{
   set_short("corta");
   set_long("larga.\n");
   add_clone("npcs",1);
   add_exit("este"    ,BTHURKUN"marisma0435.c","road");
   add_exit("sur"     ,BTHURKUN"marisma0534.c","road");
   add_exit("sudeste" ,BTHURKUN"marisma0535.c","road");
}