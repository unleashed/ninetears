#include "../path.h"
inherit CULTIVOS+"cultivos";

void setup()
{
   set_short("Sendas de Anduar");
long_desc();
   crea_bichos();
   add_exit("east"          ,CULTIVOS"senda15.c","road");
   add_exit("west"          ,CULTIVOS"senda13.c","road");
}
