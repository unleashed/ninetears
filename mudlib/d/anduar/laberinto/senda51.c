#include "../path.h"
inherit CULTIVOS+"cultivos";

void setup()
{
   set_short("Sendas de Anduar");
   crea_bichos();
   long_desc();
   add_exit("north"     ,CULTIVOS"senda57.c","road");
   add_exit("east"      ,CULTIVOS"senda52.c","road");
   add_exit("southeast" ,CULTIVOS"senda45.c","road");
   add_exit("southwest" ,CULTIVOS"senda44.c","road");
}