#include "/w/barthleby/path.h"

inherit BOSQUE"std_bosque_noella.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^GREEN%^Camino en el bosque%^RESET%^");
   long_desc_bosque_noella();



add_exit("norte", BOSQUE+"bosque_noella24","road");
add_exit("sudoeste", BOSQUE+"bosque_noella26","road");

}
