#include "../path.h"
inherit CULTIVOS+"cultivos";

void setup()
{
   set_short("Sendas de Anduar");
   crea_bichos();
   long_desc();
   add_exit("west"      ,CULTIVOS"senda76.c","road");
   add_exit("northeast" ,CULTIVOS"senda83.c","road");
   add_exit("southwest" ,CULTIVOS"senda70.c","road");
}