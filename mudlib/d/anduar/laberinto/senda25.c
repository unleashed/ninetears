#include "../path.h"
inherit CULTIVOS+"cultivos";

void setup()
{
   set_short("Sendas de Anduar");
   crea_bichos();
   long_desc();
   add_exit("west"       ,CULTIVOS"senda24.c","road");
   add_exit("northeast"  ,CULTIVOS"senda32.c","road");
}