#include "/w/barthleby/path.h"

inherit COUTO"std_senda_couto.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^CYAN%^Senda de Couto%^RESET%^");
   long_desc_couto();



add_exit("noroeste", MURALLAS_NOELLA+"ponte_en_construccion2","road");
add_exit("norte", COUTO+"couto13","road");
add_exit("sudeste", COUTO+"couto15","road");

}
