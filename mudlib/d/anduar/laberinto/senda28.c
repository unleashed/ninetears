#include "../path.h"
inherit CULTIVOS+"cultivos";

void setup()
{
   set_short("Sendas de Anduar");
   crea_bichos();
   long_desc();
   add_exit("west"         ,CULTIVOS"senda27.c","road");
   add_exit("southeast"    ,CULTIVOS"senda21.c","road");
}