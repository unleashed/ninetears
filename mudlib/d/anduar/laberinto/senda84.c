#include "../path.h"
inherit CULTIVOS+"cultivos";

void setup()
{
   set_short("Sendas de Anduar");
   crea_bichos();
   long_desc();
   add_exit("northwest" ,CULTIVOS"senda86.c","road");
   add_exit("southeast" ,CULTIVOS"senda78.c","road");
   add_exit("west"      ,CULTIVOS"senda83.c","road");
}