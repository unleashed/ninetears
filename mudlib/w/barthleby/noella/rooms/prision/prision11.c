#include "/w/barthleby/path.h"

inherit PRISION"std_prision.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^Gorband Ab-Trabasir, prisi�n de Noella%^RESET%^");
   long_desc_prision();




add_exit("noreste", PRISION+"prision10","corridor");
add_exit("sudoeste", PRISION+"prision12","corridor");

}
