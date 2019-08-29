// Minimap 2.3b.   (c) 1998 Spp .
// By Dagda
#include "/d/abarrach/path.h"
inherit "/d/abarrach/handler/base_abarrach.c";

void setup()
{
   set_short("corta");
   set_long("larga.\n");
   add_clone("npcs",1);
   add_exit("norte"   ,BTHURKUN"torre_cinco2416.c","road");
   add_exit("noreste" ,BTHURKUN"torre_seis2417.c","road");
   add_exit("este"    ,BTHURKUN"torre_cinco2517.c","road");
}