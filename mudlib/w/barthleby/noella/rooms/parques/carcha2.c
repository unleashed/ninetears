#include "/w/barthleby/path.h"

inherit PARQUES"std_parques.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^GREEN%^Parques de Carchan�m%^RESET%^");
   long_desc_carchanim();



add_exit("oeste", PARQUES+"carcha1","road");
add_exit("noroeste", PARQUES+"suleithel7","road");
add_exit("norte", PARQUES+"suleithel8","road");
add_exit("noreste", PARQUES+"suleithel9","road");
add_exit("este", PRINCIPALES+"destino","road");
add_exit("sur", PARQUES+"carcha4","road");

}
