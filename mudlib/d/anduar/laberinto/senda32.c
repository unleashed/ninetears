#include "../path.h"
inherit CULTIVOS+"cultivos";

void setup()
{
   set_short("Sendas de Anduar");
   long_desc();
   crea_bichos();
   add_exit("east"         ,CULTIVOS"senda33.c","road");
   add_exit("southwest"    ,CULTIVOS"senda25.c","road");
}