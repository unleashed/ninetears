#include "../path.h"
inherit CULTIVOS+"cultivos";

void setup()
{
   set_short("Sendas de Anduar");
long_desc();
   crea_bichos();
   add_exit("southeast"     ,CULTIVOS"senda07.c","road");
   add_exit("northwest"     ,CULTIVOS"senda16.c","road");
   add_exit("northeast"     ,CULTIVOS"senda17.c","road");
}
