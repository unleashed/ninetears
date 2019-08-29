#include "../path.h"
inherit CULTIVOS+"cultivos";

void setup()
{
   set_short("Sendas de Anduar");
   crea_bichos();
   long_desc();
   add_exit("west"      ,CULTIVOS"senda79.c","road");
   add_exit("southeast" ,CULTIVOS"senda74.c","road");
}