#include "/w/barthleby/path.h"

inherit PARQUES"std_parques.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^GREEN%^Parques de Carchan�m%^RESET%^");
   long_desc_carchanim();



//add_clone(NPC+"crea_ciudadanos", 2);

add_exit("norte", PARQUES+"suleithel7","road");
add_exit("noreste", PARQUES+"suleithel8","road");
add_exit("este", PARQUES+"carcha2","road");
add_exit("sur", PARQUES+"carcha3","road");

}
