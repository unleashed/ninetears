#include "/w/barthleby/path.h"

inherit CALLE"std_calle_principal.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^%^BLUE%^Calle Delamarth%^RESET%^");
   long_desc_calleDelamarth();




//add_clone(NPC+"crea_ciudadanos", 2);

add_exit("noreste", CALLE+"calle16","road");
add_exit("sudoeste", CALLE+"calle14","road");
}

