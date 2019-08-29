// Made by Thalos  01/04/02
// Calle Pobre

inherit "/std/suboscuridad";
#include "../../path.h"

void setup() {

   set_zone("keroon_pobre");
   set_exit_color("cyan");
   set_light(50);
   set_short("%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^BLUE%^: Cruce Calle del mercado con Calle del hurto%^RESET%^");
   set_long("\n%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^BLUE%^: Cruce Calle del mercado con Calle del hurto%^RESET%^.\n\n""Estas en el cruce  de la calle del mercado con la calle del hurto, aunque estas en la zona pobre de Keroon esta calle es amplia y esta limpia, sin duda esllo es debido a que esta es la calle que lleva al mercado donde todos los duergars realizan sus ventas y compras, tanto de los porductos que ellos fabrican, como de los pocos que necesitan comprar en el exterior.""\n\n");
   add_item(({"mercado"}),"Al final de la calle observas un gran revuelo de gente y puestos comerciales sin duda ese es el famoso mercado de Keroon.\n"); 

add_clone(NPCSKEROONPOBRE+"bixos_keroon_pobre2.c",random(5)); 

add_exit("oeste",KEROONPOBRE+"keroon_168.c","standard");
add_exit("norte",KEROONPOBRE+"keroon_146.c","standard");
add_exit("este",KEROONPOBRE+"keroon_170.c","standard");
add_exit("sur",KEROONPOBRE+"keroon_191.c","standard");
}
