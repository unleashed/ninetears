#include "../path.h"
inherit CULTIVOS+"cultivos";

void setup()
{
   set_short("Sendas de Anduar");
long_desc();
   crea_bichos();
   add_exit("northwest"     ,CULTIVOS"senda10.c","road");
   add_exit("southwest"     ,CULTIVOS"senda05.c","road");
   add_exit("east"          ,CULTIVOS"senda08.c","road");
}
