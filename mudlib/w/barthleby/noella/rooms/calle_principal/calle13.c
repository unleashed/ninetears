#include "/w/barthleby/path.h"

inherit CALLE"std_calle_principal.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^%^BLUE%^Calle de %^GREEN%^Yckull%^RESET%^");
   long_desc_calleYckull();




//add_clone(NPC+"crea_ciudadanos", 2);

add_exit("oeste", CALLEJONES+"callejon_B","road");
add_exit("norte", CALLE+"calle12","road");
add_exit("noreste", CALLEJONES+"callejon_C1","road");
add_exit("sur", MURALLAS_NOELLA"entra_muralla3","road");
}

