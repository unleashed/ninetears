#include "/w/barthleby/path.h"

inherit CAMINO_NORTE"std_caminoN.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^%^BLUE%^Camino Norte%^RESET%^");
   long_desc_cn();



   
   

add_exit("oeste", VARRO+"varro1","road");
add_exit("norte", CAMINO_NORTE+"camino_norte3","road");
add_exit("sur", CAMINO_NORTE+"camino_norte1","road");
}



