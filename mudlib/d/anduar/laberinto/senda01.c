#include "../path.h"
inherit CULTIVOS+"cultivos";

void setup()
{
   set_short("Sendas de Anduar");
long_desc();
   crea_bichos();
   add_exit("este"    ,CULTIVOS"senda02.c","road");
   add_exit("northwest"     ,CULTIVOS"senda03.c","road");
}
