#include "/w/barthleby/path.h"

inherit CAMINO_NORDESTE"std_caminoNE.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^%^BLUE%^Camino Nordeste%^RESET%^");
   long_desc_cne();




add_exit("sudoeste", CAMINO_NORDESTE+"camino_nordeste11","road");
add_exit("salida", BASE+"entrada_provisional_a_noella","road");
}



