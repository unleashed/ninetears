#include "/w/barthleby/path.h"

inherit PARQUES"std_parques.c";


void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^%^GREEN%^Paseo de Suleithel%^RESET%^");
   long_desc_suleithel();




//add_clone(NPC+"crea_ciudadanos", 1);

add_exit("oeste", PARQUES+"suleithel8","road");
add_exit("noroeste", PARQUES+"suleithel5","road");
add_exit("norte", PARQUES+"suleithel6","road");
add_exit("sur", PRINCIPALES+"destino","road");
add_exit("sudoeste", PARQUES+"carcha2","road");

}
