#include "../path.h"
inherit CULTIVOS+"cultivos";

void setup()
{
   set_short("Sendas de Anduar");
   crea_bichos();
   long_desc();
   add_exit("west"    ,CULTIVOS"senda71.c","road");
   add_exit("east"    ,CULTIVOS"senda73.c","road");
}