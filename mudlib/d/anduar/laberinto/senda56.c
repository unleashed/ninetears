#include "../path.h"
inherit CULTIVOS+"cultivos";

void setup()
{
   set_short("Sendas de Anduar");
   crea_bichos();
   long_desc();
   add_exit("east"         ,CULTIVOS"senda57.c","road");
   add_exit("northwest"    ,CULTIVOS"senda63.c","road");
}