#include "/w/barthleby/path.h"

inherit CAMINO_SUR"std_caminoS.c";


void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^%^BLUE%^Camino Sur%^RESET%^");
   long_desc_cs();




add_exit("noroeste", CAMINO_SUR+"camino_sur1","road");
add_exit("sur", CAMINO_SUR+"camino_sur3","road");
}



