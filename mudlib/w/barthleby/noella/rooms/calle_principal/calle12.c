#include "/w/barthleby/path.h"

inherit CALLE"std_calle_principal.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^%^BLUE%^Calle de %^GREEN%^Yckull%^RESET%^");
   long_desc_calleYckull();



//add_clone(NPC+"crea_ciudadanos", 2);

add_exit("norte", PRINCIPALES+"plaza_del_tapal","road");
add_exit("sur", CALLE+"calle13","road");
}

