#include "../path.h"
inherit CULTIVOS+"cultivos";

void setup()
{
   set_short("Sendas de Anduar");
   crea_bichos();
   long_desc();
   add_exit("east"         ,CULTIVOS"senda43.c","road");
   add_exit("northwest"    ,CULTIVOS"senda50.c","road");
   add_exit("southeast"    ,CULTIVOS"senda37.c","road");
}