#include "/w/barthleby/path.h"

inherit PARQUES"std_parques.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^%^GREEN%^Paseo de Suleithel%^RESET%^");
   long_desc_suleithel();




add_exit("oeste", PARQUES+"suleithel2","road");
add_exit("sur", PARQUES+"suleithel6","road");
add_exit("sudoeste", PARQUES+"suleithel5","road");

}
