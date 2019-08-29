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

add_exit("sudoeste",       BRETHEM + "gen20.c","standard");
add_exit("noreste",        BRETHEM + "gen18.c","standard");
add_exit("sudeste",        BRETHEM + "callejon002.c","standard");
add_exit("oeste",          BRETHEM + "plaza_encuentro1.c","standard");
add_exit("noroeste",       BRETHEM + "plaza_encuentro2.c","standard");
add_exit("dentro",         BRETHEM + "floristeria1.c","standard");


}
