// Minimap 2.3b.   (c) 1998 Spp .
// By Dagda
#include "/d/abarrach/path.h"
inherit "/d/abarrach/handler/base_marisma.c";

void setup()
{
   set_short("corta");
   set_long("larga.\n");
   add_clone("npcs",1);
   add_exit("noreste" ,BTHURKUN"marisma0832.c","road");
   add_exit("oeste"   ,BTHURKUN"marisma0930.c","road");
   add_exit("sur"     ,BTHURKUN"marisma1031.c","road");
}