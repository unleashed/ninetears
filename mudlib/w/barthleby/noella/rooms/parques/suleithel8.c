#include "/w/barthleby/path.h"

inherit PARQUES"std_parques.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^%^GREEN%^Paseo de Suleithel%^RESET%^");
   long_desc_suleithel();




add_exit("oeste", PARQUES+"suleithel7","road");
add_exit("noroeste", PARQUES+"suleithel4","road");
add_exit("norte", PARQUES+"suleithel5","road");
add_exit("noreste", PARQUES+"suleithel6","road");
add_exit("este", PARQUES+"suleithel9","road");
add_exit("sudeste", PRINCIPALES+"destino","road");
add_exit("sur", PARQUES+"carcha2","road");
add_exit("sudoeste", PARQUES+"carcha1","road");

}
