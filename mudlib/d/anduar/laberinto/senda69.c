#include "../path.h"
inherit CULTIVOS+"cultivos";

void setup()
{
   set_short("Sendas de Anduar");
   crea_bichos();
   long_desc();
   add_exit("east"      ,CULTIVOS"senda70.c","road");
   add_exit("southwest" ,CULTIVOS"senda61.c","road");
   add_exit("southeast" ,CULTIVOS"senda62.c","road");
}