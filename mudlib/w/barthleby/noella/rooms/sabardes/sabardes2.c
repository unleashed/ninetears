#include "/w/barthleby/path.h"

inherit SABARDES"std_sabardes.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^%^GREEN%^Ru�nas de Sabardes%^RESET%^");
   long_desc_sabardes();




add_exit("oeste",  COUTO+"couto7","road");
add_exit("noroeste",  SABARDES+"sabardes1","road");
add_exit("sudeste",  SABARDES+"sabardes3","road");
add_exit("cabanya",  SABARDES+"cabanya1","hidden");

}
