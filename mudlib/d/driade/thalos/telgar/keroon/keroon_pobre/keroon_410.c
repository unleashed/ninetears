// Made by Thalos  01/04/02
// Calle Pobre

inherit "/std/underground";
#include "../../path.h"

void setup() {

   set_zone("keroon_pobre");
   set_exit_color("cyan");
   set_light(50);
   set_short("%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^BLUE%^: Cruce Calle de la guardia con Calle de las forjas%^RESET%^");
   set_long("\n%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^BLUE%^: Cruce Calle de la guardia con Calle de las forjas%^RESET%^.\n\n""Estas en el cruce de la calle de la guardia con la calle de las forjas, en la zona pobre de Keroon, esta calle es mas conocida como de la guardia debido a que la mayoria de los guardias de la ciudad viven en esta calle, aunque eso no lo convierte en una zona segura, como puedes darte cuenta al observar las solidas puertas de los hogares y a las solapadas miradas que te hechan las mujeres a traves de los postigos de las ventanas, mientras que llaman a sus hijos para que vuelvan a casa. Al este puedes ver las puertas de las forjas""\n\n");
add_clone(NPCS+"bixos_keroon_pobre2.c",random(5)); 
add_exit("oeste",KEROONPOBRE+"keroon_409.c","standard");
add_exit("norte",KEROONPOBRE+"keroon_389.c","standard");
add_exit("este",KEROONPOBRE+"keroon_411.c","standard");
add_exit("sur",KEROONPOBRE+"keroon_434.c","standard");
}
