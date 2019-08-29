// Made by Thalos  01/04/02
// Calle Pobre

inherit "/std/underground";
#include "../../path.h"

void setup() {

   set_zone("keroon_pobre");
   set_exit_color("cyan");
   set_light(10);
   set_short("%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^BLUE%^: Calle de los vagos%^RESET%^");
   set_long("\n%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^BLUE%^: Calle de los vagos%^RESET%^.\n\n""Estas en la calle de los vagos, una de las calles de la zona pobre de Keroon, en esta calle se reunen los duergars que o bien son demasiado jovenes para trabajar y no saben que hacer con su tiempo libre, o bien aquellos que aunque estan en edad de trabajar no pueden o no quieren hacerlo. Mientras estan aqui se dedican a jugar, hablar o discurrir alguna jugarreta para gastarsela a los extranjeros que visitan la ciudad.""\n\n");
add_clone(NPCS+"bixos_keroon_pobre2.c",random(5));
add_exit("oeste",KEROONPOBRE+"keroon_323.c","standard");
add_exit("este",KEROONPOBRE+"keroon_325.c","standard");
}
