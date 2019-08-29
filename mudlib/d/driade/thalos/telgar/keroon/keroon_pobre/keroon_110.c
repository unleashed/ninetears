// Made by Thalos  01/04/02
// Calle Pobre
inherit "/std/underground";
#include "../../path.h"

void setup() {
   
   set_zone("keroon_pobre");
   set_exit_color("cyan");
   set_light(50);
   set_short("%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^BLUE%^: Cruce Calle los mendigos con Calle de la resurreccion%^RESET%^");
   set_long("\n%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^BLUE%^: Cruce Calle los mendigos con Calle de la resurreccion%^RESET%^.\n\n""Estas en el cruce de la calle los mendigos con la calle de la resurreccion, esta calle esta llena de mendigos debido a que suelen reunirse por esta zona para dividirse las zonas de trabajo, tambien puedes observar como los guardias pasan sin fijarse en ellos un instante.""\n\n");
add_clone(NPCS+"bixos_keroon_pobre.c",random(5));  
add_exit("oeste",KEROONPOBRE+"keroon_109.c","standard");
add_exit("norte",KEROONPOBRE+"keroon_89.c","standard");
add_exit("este",KEROONPOBRE+"keroon_111.c","standard");
}
