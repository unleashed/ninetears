// Minimap 2.3b.   (c) 1998 Spp .
// By Dagda
#include "/d/abarrach/path.h"
inherit "/d/abarrach/handler/base_marisma.c";

void setup()
{
   set_short("corta");
   set_long("larga.\n");
   add_clone("npcs",1);
   add_exit("oeste"   ,BTHURKUN"marisma1729.c","road");
   add_exit("sur"     ,BTHURKUN"marisma1830.c","road");
   add_exit("sudeste" ,BTHURKUN"marisma1831.c","road");
}