// Made by Thalos  01/04/02
// Calle Pobre

inherit "/std/suboscuridad";
#include "../../path.h"

void setup() {

   set_zone("keroon_pobre");
   set_exit_color("cyan");
   set_light(50);
   set_short("%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^BLUE%^: Calle de la subida%^RESET%^");
   set_long("\n%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^BLUE%^: Calle de la subida%^RESET%^.\n\n""Estas en uno de las calles de la zona pobre de Keroon, esta calle es mas conocida como de la subida ya que al final de la ligera pendiente que tiene se alcanzan las escaleras que conducen a la zona superior de la ciudad. Esta calle aunque pequenya, se encuentra limpia y cuidada sin duda esto es debido a que de vez en cuando algun noble la utiliza para darse una vuelta por la zona pobre acompanyados de sus guardaspaldas.""\n\n");

add_exit("oeste",KEROONPOBRE+"keroon_332.c","standard");
add_exit("este",KEROONPOBRE+"keroon_334.c","standard");
}
