#include "/w/barthleby/path.h"

inherit PARQUES"std_parques.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^%^GREEN%^Paseo de Suleithel%^RESET%^");
   long_desc_suleithel();




//add_clone(NPC+"crea_ciudadanos", 1);

add_exit("norte", PARQUES+"suleithel1","road");
add_exit("noreste", PARQUES+"suleithel2","road");
add_exit("este", PARQUES+"suleithel5","road");
add_exit("sudeste", PARQUES+"suleithel8","road");
add_exit("sur", PARQUES+"suleithel7","road");

}
