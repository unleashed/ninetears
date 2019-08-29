#include "../path.h"
inherit CULTIVOS+"cultivos";

void setup()
{
   set_short("Sendas de Anduar");
   crea_bichos();
   long_desc();
   add_exit("west"     ,CULTIVOS"senda53.c","road");
   add_exit("north"    ,CULTIVOS"senda60.c","road");
}