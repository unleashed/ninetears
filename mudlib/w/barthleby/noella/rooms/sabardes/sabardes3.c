#include "/w/barthleby/path.h"

inherit SABARDES"std_sabardes.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^%^GREEN%^Ru�nas de Sabardes%^RESET%^");
   long_desc_sabardes();




add_exit("noroeste",  SABARDES+"sabardes2","road");
add_exit("este",  SABARDES+"Posada","road");
add_exit("sudeste",  SABARDES+"sabardes4","road");
add_exit("cabanya",  SABARDES+"cabanya2","hidden");

}
