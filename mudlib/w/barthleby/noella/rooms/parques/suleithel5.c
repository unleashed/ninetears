#include "/w/barthleby/path.h"

inherit PARQUES"std_parques.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^%^GREEN%^Paseo de Suleithel%^RESET%^");
   long_desc_suleithel();




add_exit("oeste", PARQUES+"suleithel4","road");
add_exit("noroeste", PARQUES+"suleithel1","road");
add_exit("norte", PARQUES+"suleithel2","road");
add_exit("noreste", PARQUES+"suleithel3","road");
add_exit("este", PARQUES+"suleithel6","road");
add_exit("sudeste", PARQUES+"suleithel9","road");
add_exit("sur", PARQUES+"suleithel8","road");
add_exit("sudoeste", PARQUES+"suleithel7","road");

}
