#include "/w/barthleby/path.h"

inherit CALLE"std_calle_principal.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^%^BLUE%^Calle de %^GREEN%^Yckull%^RESET%^");
   long_desc_calleYckull();




//add_clone(NPC+"crea_ciudadanos", 2);
//add_clone(NPC+"guardia_noella", 2);

add_exit("oeste", CALLEJONES+"callejon_I3","road");
add_exit("noroeste", CALLE+"calle6","road");
add_exit("norte", PARQUES+"carcha3","road");
add_exit("noreste", PARQUES+"carcha4","road");
add_exit("este", CALLE+"calle14","road");
add_exit("sur", CALLE+"calle8","road");
}

