#include "../path.h"
inherit CULTIVOS+"cultivos";

void setup()
{
   set_short("Sendas de Anduar");
   long_desc();
   crea_bichos();
   add_exit("northwest"   ,CULTIVOS"senda42.c","road");
   add_exit("southwest"   ,CULTIVOS"senda31.c","road");
   add_exit("east"        ,CULTIVOS"senda38.c","road");
}