#include "/w/barthleby/path.h"

inherit COUTO"std_senda_couto.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^CYAN%^Senda de Couto%^RESET%^");
   long_desc_couto();



add_exit("noreste", COUTO+"couto19","road");
add_exit("sudoeste", CAMINO_SUDESTE+"camino_sudeste1","road");

}
