#include "../path.h"
inherit CULTIVOS+"cultivos";

void setup()
{
   set_short("Sendas de Anduar");
long_desc();
   crea_bichos();
   add_exit("west"         ,CULTIVOS"senda21.c","road");
   add_exit("northwest"    ,CULTIVOS"senda29.c","road");
   add_exit("northeast"    ,CULTIVOS"senda30.c","road");
}
