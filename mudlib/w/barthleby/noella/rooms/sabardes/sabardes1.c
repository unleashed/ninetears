#include "/w/barthleby/path.h"

inherit SABARDES"std_sabardes.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^%^GREEN%^Ru�nas de Sabardes%^RESET%^");
   long_desc_sabardes();




add_exit("noroeste",  COUTO+"couto6","road");
add_exit("sudeste",  SABARDES+"sabardes2","road");

}
