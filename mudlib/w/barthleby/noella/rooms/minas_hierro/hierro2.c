#include "/w/barthleby/path.h"

inherit HIERRO"std_hierro.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^RED%^Minas de hierro de Noella%^RESET%^");
   long_desc_hierro();




add_exit("noreste", HIERRO+"hierro1","road");
add_exit("sur", HIERRO+"hierro3","road");

}

