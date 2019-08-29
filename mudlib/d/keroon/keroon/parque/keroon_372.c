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
add_exit("oeste",PARQUE+"keroon_371.c","standard");
add_exit("norte",PARQUE+"keroon_346.c","standard");
add_exit("noreste",PARQUE+"keroon_347.c","standard");
add_exit("sudeste",PARQUE+"keroon_394.c","standard");
add_exit("sur",PARQUE+"keroon_393.c","standard");
}
