// Made by Thalos  01/04/02
// Calle Pobre

inherit "/std/underground";
#include "../../path.h"

void setup() {

   set_zone("keroon_pobre");
   set_exit_color("cyan");
   set_light(50);
   set_short("%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^BLUE%^: Cruce Calle las tabernas con Calle del hurto%^RESET%^");
   set_long("\n%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^BLUE%^: Cruce Calle las tabernas con Calle del hurto%^RESET%^.\n\n""Estas en el cruce que une la calle de las tabernas con la calle del hurto, ves varias tabernas en los alrededores, tambien puedes observar varias peleas desatadas sin duda por las bebidas que se sirven en la zona.""\n\n");
add_item(({"pelea","peleas"}),"Ves a varios duergars zurrandose entre ellos, en medio de gritos e insultos, no sabes bien el porque de la pelea pero como no va contigo los dejas en paz.\n"); 
add_exit("oeste",KEROONPOBRE+"keroon_40.c","standard");
add_exit("este",KEROONPOBRE+"keroon_42.c","standard");
add_exit("sur",KEROONPOBRE+"keroon_64.c","standard");
}
