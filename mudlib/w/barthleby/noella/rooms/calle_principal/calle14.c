#include "/w/barthleby/path.h"

inherit CALLE"std_calle_principal.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^%^BLUE%^Calle Delamarth%^RESET%^");
   long_desc_calleDelamarth();




add_exit("oeste", CALLE+"calle7","road");
add_exit("noreste", CALLE+"calle15","road");
}

