#include "/w/barthleby/path.h"

inherit CALLE"std_calle_principal.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^%^BLUE%^Calle Delamarth%^RESET%^");
   long_desc_calleDelamarth();




//add_clone(NPC+"guardia_noella", 1);

add_exit("oeste", CALLE+"calle17","road");
add_exit("noreste", MURALLAS_NOELLA+"muralla43","road");
add_exit("sudoeste", CALLEJONES+"callejon_F5","road");
}

