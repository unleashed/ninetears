#include "../path.h"
inherit CULTIVOS+"cultivos";

void setup()
{
   set_short("Sendas de Anduar");
   crea_bichos();
   long_desc();
   add_exit("northwest"    ,CULTIVOS"senda33.c","road");
   add_exit("northeast"    ,CULTIVOS"senda34.c","road");
   add_exit("southwest"    ,CULTIVOS"senda19.c","road");
}