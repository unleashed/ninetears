#include "/w/barthleby/path.h"

inherit CAMINO_SUDESTE"std_caminoSE.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^%^BLUE%^Camino Sudeste%^RESET%^");
   long_desc_cse();





add_exit("noroeste", CAMINO_SUDESTE+"camino_sudeste1","road");
add_exit("sudeste", CAMINO_SUDESTE+"camino_sudeste3","road");
}



