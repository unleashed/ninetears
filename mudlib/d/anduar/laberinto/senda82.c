#include "../path.h"
inherit CULTIVOS+"cultivos";

void setup()
{
   set_short("Sendas de Anduar");
   crea_bichos();
   long_desc();
   add_exit("northeast" ,CULTIVOS"senda85.c","road");
   add_exit("west"      ,CULTIVOS"senda81.c","road");
   add_exit("southeast" ,CULTIVOS"senda76.c","road");
}