// Made by Thalos  01/04/02
//Parque
#include "../../path.h"

inherit PARQUE+"parque.c";

void setup() {

   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^GREEN%^: Parque de los conquistadores%^RESET%^");
   parque_desc();
   
add_clone(NPCSPARQUE+"prostitutas.c",random(3)); 
add_exit("noroeste",PARQUE+"keroon_330.c","standard");
add_exit("este",KEROONPOBRE+"keroon_348.c","standard");
add_exit("sur",PARQUE+"keroon_373.c","standard");
add_exit("sudoeste",PARQUE+"keroon_372.c","standard");
}
