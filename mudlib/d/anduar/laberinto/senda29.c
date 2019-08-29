#include "../path.h"
inherit CULTIVOS+"cultivos";

void setup()
{
   set_short("Sendas de Anduar");
   crea_bichos();
   long_desc();
   add_exit("north"     ,CULTIVOS"senda35.c","road");
   add_exit("southeast" ,CULTIVOS"senda22.c","road");
}