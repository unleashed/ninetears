#include "/w/barthleby/path.h"

inherit CALLE"std_calle_principal.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^%^BLUE%^Calle de %^GREEN%^Yckull%^RESET%^");
   long_desc_calleYckull();



//add_clone(NPC+"crea_ciudadanos", 1);

add_exit("oeste", CALLEJONES+"callejon_D3","road");
add_exit("noreste", CALLE+"calle9","road");
add_exit("sur",CALLE+"calle11","road");
add_exit("dentro", PRINCIPALES+"tasca_tipica","road");
add_exit("templo", PRINCIPALES+"templo_barthleby1","road");
}

