#include "../path.h"
inherit CULTIVOS+"cultivos";

void setup()
{
   set_short("Sendas de Anduar");
long_desc();
long_desc();
   crea_bichos();
   add_exit("east"          ,CULTIVOS"senda19.c","road");
   add_exit("west"          ,CULTIVOS"senda17.c","road");
}
