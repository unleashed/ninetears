#include "/w/barthleby/path.h"

inherit CAMINO_SUR"std_caminoS.c";


void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^%^BLUE%^Camino Sur%^RESET%^");
   long_desc_cs();




add_exit("norte", MURALLAS_NOELLA+"ponte_S2","road");
add_exit("este", BOSQUE+"bosque_noella37","road");
add_exit("sudeste", CAMINO_SUR+"camino_sur2","road");
}



