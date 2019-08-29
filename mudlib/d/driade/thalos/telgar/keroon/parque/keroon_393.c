// Made by Thalos  01/04/02
//Parque
#include "../../path.h"

inherit PARQUE+"parque.c";

void setup() {

   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^GREEN%^: Parque de los conquistadores%^RESET%^");
   parque_desc();
   
add_clone(NPCSPARQUE+"chulo.c",random(1)); 
add_clone(NPCSPARQUE+"prostitutas.c",random(3)); 
add_exit("oeste",PARQUE+"keroon_392.c","standard");
add_exit("noroeste",PARQUE+"keroon_371.c","standard");
add_exit("norte",PARQUE+"keroon_372.c","standard");
add_exit("sur",KEROONPOBRE+"keroon_414.c","standard");
}
