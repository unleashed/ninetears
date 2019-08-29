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

add_exit("norte",    BRETHEM + "gen14.c","standard");
add_exit("sur",      BRETHEM + "castros1.c","standard");
add_exit("oeste",    BRETHEM + "plaza_eleisson3.c","standard");


}
