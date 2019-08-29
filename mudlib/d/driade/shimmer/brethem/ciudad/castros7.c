/* By Shimmer */

#define CREATOR "shimmer"

#include "../../path.h"

inherit BRETHEM+"cityroom.c";


void setup() {

   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^Ciudad de Brethem : %^BOLD%^GREEN%^Calle de los Castros%^RESET%^");
   long_desc();

   crea_npcs();

add_exit("noroeste",   BRETHEM + "castros8.c","standard");
add_exit("sur",        BRETHEM + "castros6.c","standard");


}
