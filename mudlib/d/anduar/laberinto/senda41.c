#include "../path.h"
inherit CULTIVOS+"cultivos";

void setup()
{
   set_short("Sendas de Anduar");
   long_desc();
   crea_bichos();
   add_exit("northwest"   ,CULTIVOS"senda49.c","road");
   add_exit("south"       ,CULTIVOS"senda36.c","road");
}
