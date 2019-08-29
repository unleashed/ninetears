#include "../path.h"
inherit CULTIVOS+"cultivos";

void setup()
{
   set_short("Sendas de Anduar");
   crea_bichos();
   long_desc();
   add_exit("northeast" ,CULTIVOS"senda81.c","road");
   add_exit("south"     ,CULTIVOS"senda68.c","road");
}