#include "../path.h"
inherit CULTIVOS+"cultivos";

void setup()
{
   set_short("Sendas de Anduar");
   crea_bichos();
   long_desc();
   add_exit("east"   ,CULTIVOS"senda66.c","road");
   add_exit("west"   ,CULTIVOS"senda64.c","road");
}
