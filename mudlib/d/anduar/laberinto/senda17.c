#include "../path.h"
inherit CULTIVOS+"cultivos";

void setup()
{
   set_short("Sendas de Anduar");
long_desc();
   crea_bichos();
   add_exit("east"          ,CULTIVOS"senda18.c","road");
   add_exit("southwest"     ,CULTIVOS"senda10.c","road");
}
