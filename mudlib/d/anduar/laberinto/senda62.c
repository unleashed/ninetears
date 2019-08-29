#include "../path.h"
inherit CULTIVOS+"cultivos";

void setup()
{
   set_short("Sendas de Anduar");
   crea_bichos();
   long_desc();
   add_exit("east"      ,CULTIVOS"senda63.c","road");
   add_exit("southwest" ,CULTIVOS"senda55.c","road");
   add_exit("northwest" ,CULTIVOS"senda69.c","road");
}