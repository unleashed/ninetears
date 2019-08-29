#include "../path.h"
inherit CULTIVOS+"cultivos";

void setup()
{
   set_short("Sendas de Anduar");
   crea_bichos();
   long_desc();
   add_exit("northwest" ,CULTIVOS"senda87.c","road");
   add_exit("southeast" ,CULTIVOS"senda84.c","road");
}