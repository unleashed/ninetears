#include "../path.h"
inherit CULTIVOS+"cultivos";

void setup()
{
   set_short("Sendas de Anduar");
   crea_bichos();
   long_desc();
   add_exit("northwest" ,CULTIVOS"senda84.c","road");
   add_exit("southwest" ,CULTIVOS"senda73.c","road");
   add_exit("east"     ,CULTIVOS"senda79.c","road");
}
