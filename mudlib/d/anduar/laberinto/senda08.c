#include "../path.h"
inherit CULTIVOS+"cultivos";

void setup()
{
   set_short("Sendas de Anduar");
long_desc();
   crea_bichos();
   add_exit("southeast"     ,CULTIVOS"senda06.c","road");
   add_exit("west"          ,CULTIVOS"senda07.c","road");
   add_exit("northeast"     ,CULTIVOS"senda11.c","road");
}
