#include "../path.h"
inherit CULTIVOS+"cultivos";

void setup()
{
   set_short("Sendas de Anduar");
   crea_bichos();
   long_desc();
   add_exit("north"     ,CULTIVOS"senda75.c","road");
   add_exit("southeast" ,CULTIVOS"senda61.c","road");
}