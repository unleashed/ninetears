#include "../path.h"
inherit CULTIVOS+"cultivos";

void setup()
{
   set_short("Sendas de Anduar");
   crea_bichos();
   long_desc();
   add_exit("southwest"   ,CULTIVOS"senda46.c","road");
   add_exit("east"        ,CULTIVOS"senda54.c","road");
}