// Made by Thalos  01/04/02
// Calle Pobre

inherit "/std/suboscuridad";
#include "../../path.h"

void setup() {

   set_zone("keroon_pobre");
   set_exit_color("cyan");
   set_light(50);
   set_short("%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^BLUE%^: Cruce Calle de la forja y Parque%^RESET%^");
   set_long("\n%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^BLUE%^: Cruce Calle de la forja y Parque%^RESET%^.\n\n""Estas en una de las calles de la zona pobre de Keroon, esta calle es amplia y grande debido a que por ella circulan los carromatos que trasportan el hierro, acero y demas materiales que se producen en las forjas para llevarlo a los maestros herreros y orfebres para que lo trabajen, moldeen y construyan sus maravillosas armas y armaduras, de vez en cuando se cae algun pedazo de metal de los carromatos.Al norte de aqui puedes ver el parque de Keroon""\n\n");

add_exit("oeste",KEROONPOBRE+"keroon_411.c","standard");
add_exit("norte",PARQUE+"keroon_391.c","standard");
add_exit("este",KEROONPOBRE+"keroon_413.c","standard");
}
