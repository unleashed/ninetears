// Made by Thalos  01/04/02
// Calle Pobre
inherit "/std/underground";
#include "../../path.h"

void setup() {
   
   set_zone("keroon_pobre");
   set_exit_color("cyan");
   set_light(50);
      set_short("%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^BLUE%^: Cruce Calle los mendigos con Avenida de la separacion%^RESET%^");
   set_long("\n%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^BLUE%^: Cruce Calle los mendigos con Avenida de la separacion%^RESET%^.\n\n""Estas en el cruce  de la calle los mendigos con la calle de los tullidos, esta calle esta llena de mendigos debido a que suelen reunirse por esta zona para dividirse las zonas de trabajo, tambien puedes observar como los guardias pasan sin fijarse en ellos un instante.""\n\n");
     add_clone(NPCS+"bixos_keroon_pobre2.c",random(5)); 
add_exit("oeste",KEROONPOBRE+"keroon_107.c","standard");
add_exit("este",KEROONPOBRE+"keroon_109.c","standard");
add_exit("sur",KEROONPOBRE+"keroon_123.c","standard");
}
