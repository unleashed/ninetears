#include "../path.h"
inherit CULTIVOS+"cultivos";

void setup()
{
   set_short("Sendas de Anduar");
   crea_bichos();
   long_desc();
   add_exit("west"        ,CULTIVOS"senda46.c","road");
   add_exit("southeast"   ,CULTIVOS"senda40.c","road");
   add_exit("east"        ,CULTIVOS"senda48.c","road");
}