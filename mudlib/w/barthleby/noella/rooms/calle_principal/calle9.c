#include "/w/barthleby/path.h"

inherit CALLE"std_calle_principal.c";


void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^%^BLUE%^Calle de %^GREEN%^Yckull%^RESET%^");
   long_desc_calleYckull();




add_clone(NPC+"crea_ciudadanos", 3);

add_exit("norte", CALLE+"calle8","road");
add_exit("sudeste", CALLEJONES+"callejon_E","road");
add_exit("sudoeste", CALLE+"calle10","road");
}

