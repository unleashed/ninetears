#include "../path.h"
inherit CULTIVOS+"cultivos";

void setup()
{
   set_short("Sendas de Anduar");
   long_desc();
   crea_bichos();
   add_exit("north"     ,CULTIVOS"senda41.c","road");
   add_exit("southeast" ,CULTIVOS"senda30.c","road");
}