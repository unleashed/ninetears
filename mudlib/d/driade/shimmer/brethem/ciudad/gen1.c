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

add_exit("oeste",    BRETHEM + "gen2.c","standard");
add_exit("este",     BRETHEM + "estatualeon.c","standard");
add_exit("norte",    BRETHEM + "manco1.c","standard");

}
