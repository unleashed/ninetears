#include "../path.h"
inherit CULTIVOS+"cultivos";

void setup()
{
   set_short("Sendas de Anduar");
   crea_bichos();
   long_desc();
   add_exit("northwest" ,CULTIVOS"senda80.c","road");
   add_exit("southwest" ,CULTIVOS"senda66.c","road");
   add_exit("south"     ,CULTIVOS"senda67.c","road");
}