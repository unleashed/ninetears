#include "../path.h"
inherit CULTIVOS+"cultivos";

void setup()
{
   set_short("Sendas de Anduar");
   crea_bichos();
   long_desc();
   add_exit("north"   ,CULTIVOS"senda34.c","road");
   add_exit("south"   ,CULTIVOS"senda20.c","road");
   add_exit("east"    ,CULTIVOS"senda28.c","road");
}