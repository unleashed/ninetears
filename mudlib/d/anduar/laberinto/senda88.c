#include "../path.h"
inherit CULTIVOS+"cultivos";

void setup()
{
   set_short("Sendas de Anduar");
   crea_bichos();
   long_desc();
   add_exit("southwest" ,CULTIVOS"senda87.c","road");
   add_exit("noreste" ,"/d/anduar/poblado/g0407.c","road");
}
