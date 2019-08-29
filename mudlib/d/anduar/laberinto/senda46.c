#include "../path.h"
inherit CULTIVOS+"cultivos";

void setup()
{
   set_short("Sendas de Anduar");
   crea_bichos();
   long_desc();
   add_exit("west"      ,CULTIVOS"senda45.c","road");
   add_exit("east"      ,CULTIVOS"senda47.c","road");
   add_exit("northeast" ,CULTIVOS"senda53.c","road");
}