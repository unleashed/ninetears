// Made by Thalos  01/04/02
// Calle Pobre

inherit "/std/suboscuridad";
#include "../../path.h"

void setup() {

   set_zone("keroon_pobre");
   set_exit_color("cyan");
   set_light(50);
   set_short("%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^BLUE%^: Cruce Calle de la forja y Avenida de la Separacion%^RESET%^");
   set_long("\n%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^BLUE%^: Cruce Calle de la forja y Avenida de la Separacion%^RESET%^.\n\n""Estas en el cruce entre la calle de la forja y la avenida de la Separacion, una de las calles de la zona pobre de Keroon, esta calle es amplia y grande debido a que por ella circulan los carromatos que trasportan el hierro, acero y demas materiales que se producen en las forjas para llevarlo a los maestros herreros y orfebres para que lo trabajen, moldeen y construyan sus maravillosas armas y armaduras, de vez en cuando se cae algun pedazo de metal de los carromatos.""\n\n");
add_clone(NPCSKEROONPOBRE+"bixos_keroon_pobre.c",random(5));
add_exit("oeste",KEROONPOBRE+"keroon_415.c","standard");
add_exit("norte",KEROONPOBRE+"keroon_395.c","standard");

}
