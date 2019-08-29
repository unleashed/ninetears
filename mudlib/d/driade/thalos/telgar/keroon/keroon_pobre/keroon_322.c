// Made by Thalos  01/04/02
// Calle Pobre

inherit "/std/underground";
#include "../../path.h"

void setup() {

   set_zone("keroon_pobre");
   set_exit_color("cyan");
   set_light(50);
   set_short("%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^BLUE%^: Cruce Calle del hurto con Calle de los vagos%^RESET%^");
   set_long("\n%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^BLUE%^: Cruce Calle del hurto con Calle de los vagos%^RESET%^.\n\n""Estas en el Cruce Calle del hurto con Calle de los vagos, en la zona pobre de Keroon, esta calle es mas conocida como del hurto debido al importante numero de robos de que se producen en la zona porque atraviesa la ciudad de lado a lado y un ladronzuelo puede perderse por ella antes de que pueda ser capturado, ademas su cercania con el mercado proporciona buenas victimas para estos ladronzuelos.""\n\n");
add_clone(NPCS+"bixos_keroon_pobre2.c",random(5)); 
add_exit("oeste",KEROONPOBRE+"keroon_321.c","standard");
add_exit("norte",KEROONPOBRE+"keroon_306.c","standard");
add_exit("este",KEROONPOBRE+"keroon_323.c","standard");
add_exit("sur",KEROONPOBRE+"keroon_341.c","standard");
}
