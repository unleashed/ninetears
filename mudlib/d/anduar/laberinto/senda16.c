#include "../path.h"
inherit CULTIVOS+"cultivos";

void setup()
{
   set_short("Sendas de Anduar");
long_desc();
   crea_bichos();
   add_exit("northeast"          ,CULTIVOS"senda24.c","road");
   add_exit("northwest"          ,CULTIVOS"senda23.c","road");
   add_exit("southeast"          ,CULTIVOS"senda10.c","road");
}
