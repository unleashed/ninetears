#include "../path.h"
inherit CULTIVOS+"cultivos";

void setup()
{
   set_short("Sendas de Anduar");
long_desc();
   crea_bichos();
   add_exit("oeste"         ,CULTIVOS"senda01.c","road");
   add_exit("northeast"     ,CULTIVOS"senda04.c","road");
}
