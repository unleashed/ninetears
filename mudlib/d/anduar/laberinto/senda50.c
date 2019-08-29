#include "../path.h"
inherit CULTIVOS+"cultivos";

void setup()
{
   set_short("Sendas de Anduar");
   crea_bichos();
   long_desc();
   add_exit("north"     ,CULTIVOS"senda55.c","road");
   add_exit("southeast" ,CULTIVOS"senda42.c","road");
}