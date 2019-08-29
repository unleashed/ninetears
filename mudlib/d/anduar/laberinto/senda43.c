#include "../path.h"
inherit CULTIVOS+"cultivos";

void setup()
{
   set_short("Sendas de Anduar");
   crea_bichos();
   long_desc();
   add_exit("west"       ,CULTIVOS"senda42.c","road");
   add_exit("east"       ,CULTIVOS"senda44.c","road");
}