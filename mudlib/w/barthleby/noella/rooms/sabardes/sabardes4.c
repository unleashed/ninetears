#include "/w/barthleby/path.h"

inherit SABARDES"std_sabardes.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^%^GREEN%^Ru�nas de Sabardes%^RESET%^");
   long_desc_sabardes();




add_exit("noroeste",  SABARDES+"sabardes3","road");
add_exit("este",  SABARDES+"sabardes5","road");
add_exit("sur",  BREIX+"breix1","road");

}

