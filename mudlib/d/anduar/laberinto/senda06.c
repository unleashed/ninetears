#include "../path.h"
inherit CULTIVOS+"cultivos";

void setup()
{
   set_short("Sendas de Anduar");
long_desc();
   crea_bichos();
   add_exit("southwest"     ,CULTIVOS"senda04.c","road");
   add_exit("northwest"     ,CULTIVOS"senda08.c","road");
   add_exit("northeast"     ,CULTIVOS"senda09.c","road");
}
