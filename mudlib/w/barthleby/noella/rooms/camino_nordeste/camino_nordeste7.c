#include "/w/barthleby/path.h"

inherit CAMINO_NORDESTE"std_caminoNE.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^%^BLUE%^Camino Nordeste%^RESET%^");
   long_desc_cne();





add_exit("oeste", CAMINO_NORDESTE+"camino_nordeste6","road");
add_exit("este", CAMINO_NORDESTE+"camino_nordeste8","road");
}



