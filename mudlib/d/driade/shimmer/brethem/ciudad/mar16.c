/* By Shimmer */

#include "../../path.h"

inherit BRETHEM+"cityroom.c";


void setup() {
   
   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^Ciudad de Brethem : %^BOLD%^BLUE%^Calle del Mar%^RESET%^");
   long_desc_callemar();  

   crea_npcs_callemar();

add_exit("sudoeste", BRETHEM + "mar17.c","standard");
add_exit("este",     BRETHEM + "mar15.c","standard");
add_exit("norte",    BRETHEM + "plaza_eleisson4.c","standard");

}