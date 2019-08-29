/* By Shimmer */

#define CREATOR "shimmer"

#include "../../path.h"

inherit BRETHEM+"cityroom.c";


void setup() {

   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^Ciudad de Brethem : %^BOLD%^WHITE%^Calle del General%^RESET%^");
   long_desc();


   crea_npcs();

add_exit("sur",        BRETHEM + "bandor1.c","standard");
add_exit("noreste",    BRETHEM + "gen19.c","standard");
add_exit("noroeste",   BRETHEM + "plaza_encuentro3.c","standard");
add_exit("norte",      BRETHEM + "plaza_encuentro1.c","standard");

}
