#include "/w/barthleby/path.h"

inherit CALLE"std_calle_principal.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^%^BLUE%^Calle de %^GREEN%^Yckull%^RESET%^");
   long_desc_calleYckull();




add_exit("norte", CALLE+"calle10","road");
add_exit("noreste", CALLEJONES+"callejon_F1","road");
add_exit("sur", PRINCIPALES+"plaza_del_tapal","road");
add_exit("dentro", PRINCIPALES+"leyes","road");
}

