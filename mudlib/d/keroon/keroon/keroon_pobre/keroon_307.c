// Made by Thalos  01/04/02
// Calle Pobre

inherit "/std/suboscuridad";
#include "../../path.h"

void setup() {

   set_zone("keroon_pobre");
   set_exit_color("cyan");
   set_light(50);
   set_short("%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^BLUE%^: Calle de la guardia%^RESET%^");
   set_long("\n%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^BLUE%^: Calle de la guardia%^RESET%^.\n\n""Estas en una de las calles de la zona pobre de Keroon, esta calle es mas conocida como de la guardia debido a que la mayoria de los guardias de la ciudad viven en esta calle, aunque eso no lo convierte en una zona segura, como puedes darte cuenta al observar las solidas puertas de los hogares y a las solapadas miradas que te hechan las mujeres a traves de los postigos de las ventanas, mientras que llaman a sus hijos para que vuelvan a casa.""\n\n");

add_exit("norte",KEROONPOBRE+"keroon_287.c","standard");
add_exit("sur",KEROONPOBRE+"keroon_326.c","standard");
}
