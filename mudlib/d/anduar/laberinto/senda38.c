#include "../path.h"
inherit CULTIVOS+"cultivos";

void setup()
{
   set_short("Sendas de Anduar");
   long_desc();
   crea_bichos();
   add_exit("west"    ,CULTIVOS"senda37.c","road");
   add_exit("east"    ,CULTIVOS"senda39.c","road");
}