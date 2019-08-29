#include "../path.h"
inherit CULTIVOS+"cultivos";

void setup()
{
   set_short("Sendas de Anduar");
long_desc();
   crea_bichos();
   add_exit("west"          ,CULTIVOS"senda14.c","road");
   add_exit("east"          ,SENDA"s1.c","road");
   add_exit("north"         ,CULTIVOS"senda21.c","road");
}
