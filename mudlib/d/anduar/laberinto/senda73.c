#include "../path.h"
inherit CULTIVOS+"cultivos";

void setup()
{
   set_short("Sendas de Anduar");
   crea_bichos();
   long_desc();
   add_exit("northeast"   ,CULTIVOS"senda78.c","road");
   add_exit("southeast"   ,CULTIVOS"senda64.c","road");
   add_exit("west"        ,CULTIVOS"senda72.c","road");
}