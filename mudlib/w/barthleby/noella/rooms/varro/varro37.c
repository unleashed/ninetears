#include "/w/barthleby/path.h"

inherit VARRO"std_varro.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^%^ORANGE%^Minas de Varro%^RESET%^");
   long_desc_varro();



add_exit("sur", VARRO+"varro36","road");
add_exit("abajo", PRINCIPALES+"jakel","road");
}

