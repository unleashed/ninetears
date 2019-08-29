#include "../path.h"
inherit CULTIVOS+"cultivos";

void setup()
{
   set_short("Sendas de Anduar");
   crea_bichos();
   long_desc();
   add_exit("northeast" ,CULTIVOS"senda87.c","road");
   add_exit("southwest" ,CULTIVOS"senda82.c","road");
}