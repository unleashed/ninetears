// Minimap 2.3b.   (c) 1998 Spp .
// By Dagda
#include "/d/abarrach/path.h"
inherit "/d/abarrach/handler/base_abarrach.c";

void setup()
{
   set_short("corta");
   set_long("larga.\n");
   add_clone("npcs",1);
   add_exit("noreste" ,BTHURKUN"torre_tres2122.c","road");
   add_exit("oeste"   ,BTHURKUN"torre_cuatro2220.c","road");
   add_exit("sur"     ,BTHURKUN"torre_cuatro2321.c","road");
}