#include "/w/barthleby/path.h"

inherit CALLE"std_calle_principal.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^%^BLUE%^Calle de %^GREEN%^Yckull%^RESET%^");
   long_desc_calleYckull();




//add_clone(NPC+"crea_ciudadanos", 1);

add_exit("oeste", CALLEJONES+"callejon_J6","road");
add_exit("norte", CALLE+"calle4","road");
add_exit("sur", CALLE+"calle6","road");
}

