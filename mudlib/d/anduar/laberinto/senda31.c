#include "../path.h"
inherit CULTIVOS+"cultivos";

void setup()
{
   set_short("Sendas de Anduar");
   long_desc();
   crea_bichos();
   add_exit("northeast"   ,CULTIVOS"senda37.c","road");
   add_exit("southwest"   ,CULTIVOS"senda23.c","road");
}