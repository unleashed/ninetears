#include "../path.h"
inherit CULTIVOS+"cultivos";

void setup()
{
   set_short("Sendas de Anduar");
long_desc();
   crea_bichos();
   add_exit("northeast"   ,CULTIVOS"senda26.c","road");
   add_exit("west"        ,CULTIVOS"senda18.c","road");
}
