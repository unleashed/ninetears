#include "../path.h"
inherit CULTIVOS+"cultivos";

void setup()
{
   set_short("Sendas de Anduar");
   long_desc();
   crea_bichos();
   add_exit("south"        ,CULTIVOS"senda27.c","road");
   add_exit("southwest"    ,CULTIVOS"senda26.c","road");
   add_exit("northeast"    ,CULTIVOS"senda40.c","road");
}