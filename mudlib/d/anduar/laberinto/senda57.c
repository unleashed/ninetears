#include "../path.h"
inherit CULTIVOS+"cultivos";

void setup()
{
   set_short("Sendas de Anduar");
   crea_bichos();
   long_desc();
   add_exit("northeast"   ,CULTIVOS"senda64.c","road");
   add_exit("south"       ,CULTIVOS"senda51.c","road");
   add_exit("west"        ,CULTIVOS"senda56.c","road");
}