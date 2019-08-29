#include "../path.h"
inherit CULTIVOS+"cultivos";

void setup()
{
   set_short("Sendas de Anduar");
   crea_bichos();
   long_desc();
   add_exit("north"     ,CULTIVOS"senda74.c","road");
   add_exit("south"     ,CULTIVOS"senda60.c","road");
   add_exit("southwest" ,CULTIVOS"senda59.c","road");
}