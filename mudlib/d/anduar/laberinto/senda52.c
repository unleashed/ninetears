#include "../path.h"
inherit CULTIVOS+"cultivos";

void setup()
{
   set_short("Sendas de Anduar");
   crea_bichos();
   long_desc();
   add_exit("west"         ,CULTIVOS"senda51.c","road");
   add_exit("northeast"    ,CULTIVOS"senda58.c","road");
}