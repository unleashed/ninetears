#include "/w/barthleby/path.h"

inherit MERCADO"std_mercado.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^Mercado de Noella%^RESET%^");
   long_desc_mercado();




add_exit("oeste", CALLEJONES+"callejon_G1","road");
add_exit("noroeste", MERCADO+"mercado9","road");
add_exit("norte", MERCADO+"mercado10","road");
add_exit("noreste", MERCADO+"mercado11","road");
add_exit("este", MERCADO+"mercado15","road");
add_exit("sudeste", CALLEJONES+"callejon_A5","road");
add_exit("sudoeste", CALLEJONES+"callejon_C4","road");
}
