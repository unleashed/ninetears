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
add_exit("norte",PARQUE+"keroon_370.c","standard");
add_exit("noreste",PARQUE+"keroon_371.c","standard");
add_exit("este",PARQUE+"keroon_392.c","standard");
add_exit("sur",KEROONPOBRE+"keroon_412.c","standard");
}
