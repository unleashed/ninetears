// Made by Thalos  01/04/02
// Calle Pobre

inherit "/std/suboscuridad";
#include "../../path.h"

void setup() {

   set_zone("keroon_pobre");
   set_exit_color("cyan");
   set_light(10);
   set_short("%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^BLUE%^: Callejon de los meados%^RESET%^");
   set_long("\n%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^BLUE%^: Callejon de los meados%^RESET%^.\n\n""Estas en uno de los callejones de la zona pobre de Keroon, no sabes cual era su nombre antiguamente, pero a tu nariz no le queda ninguna duda del porque de su nombre actual, por todos lados encuentras a borrachos meando y vomitando por los rincones, te tapas la nariz y pasas lo mas rapidamente posible.""\n\n");

add_smell(({"calle","aire"}),"El aire esta lleno del olor de los orines y de otras sustancias que no quieres ni saber que son.\n");

add_exit("oeste",KEROONPOBRE+"keroon_12.c","standard");
add_exit("sudeste",KEROONPOBRE+"keroon_31.c","standard");
}
