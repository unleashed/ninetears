#include "../path.h"
inherit CULTIVOS+"cultivos";

void setup()
{
   set_short("Sendas de Anduar");
   long_desc();
   crea_bichos();
   add_exit("northwest"   ,CULTIVOS"senda39.c","road");
   add_exit("southeast"   ,CULTIVOS"senda26.c","road");
   add_exit("west"        ,CULTIVOS"senda32.c","road");
}