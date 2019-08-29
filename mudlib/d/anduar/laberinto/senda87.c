#include "../path.h"
inherit CULTIVOS+"cultivos";

void setup()
{
   set_short("Sendas de Anduar");
   crea_bichos();
   long_desc();
   add_exit("southeast" ,CULTIVOS"senda86.c","road");
   add_exit("southwest" ,CULTIVOS"senda85.c","road");
   add_exit("northwest" ,SENDA"s21.c","road");
//add_exit("noreste" ,CULTIVOS"senda88.c","road");
}
