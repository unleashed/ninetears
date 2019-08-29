// Made by Thalos  01/04/02
// Calle Pobre
inherit "/std/suboscuridad";
#include "../../path.h"

void setup() {
   
   set_zone("keroon_pobre");
   set_exit_color("cyan");
   set_light(50);
   set_short("%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^BLUE%^: Calle los mendigos%^RESET%^");
   set_long("\n%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^BLUE%^: Calle los mendigos%^RESET%^.\n\n"
   "Estas en una retorcida calle de la zona pobre de Keroon puedes ver un reguero de agua sucia"
   "por el centro de la calle, esta calle es mas conocida como de los mendigos debido a que suelen"
   "reunirse por esta zona para dividirse las zonas de trabajo, tambien puedes observar como los"
   "guardias pasan sin fijarse en ellos un instante.""\n\n");

add_item(({"reguero","agua"}),"Es un asqueroso riachuelo, que discurre el centro de la calle arrastrando parte de la porqueria de la ciudad.\n");    

add_clone(NPCSKEROONPOBRE+"bixos_keroon_pobre.c",random(5));

add_exit("oeste",KEROONPOBRE+"keroon_103.c","standard");
add_exit("este",KEROONPOBRE+"keroon_105.c","standard");
}
