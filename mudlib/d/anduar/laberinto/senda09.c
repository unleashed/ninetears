#include "../path.h"
inherit CULTIVOS+"cultivos";

void setup()
{
   set_short("Sendas de Anduar");
long_desc();
   crea_bichos();
   add_exit("northwest"     ,CULTIVOS"senda11.c","road");
   add_exit("northeast"     ,CULTIVOS"senda13.c","road");
   add_exit("southwest"     ,CULTIVOS"senda06.c","road");
}
