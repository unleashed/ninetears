#include "/w/barthleby/path.h"

inherit CAMINO_NORDESTE"std_caminoNE.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^%^BLUE%^Camino Nordeste%^RESET%^");
   long_desc_cne();

   



add_exit("noreste", CAMINO_NORDESTE+"camino_nordeste3","road");
add_exit("sur", PRISION+"prision1","road");
add_exit("sudoeste", CAMINO_NORDESTE+"camino_nordeste1","road");
}



