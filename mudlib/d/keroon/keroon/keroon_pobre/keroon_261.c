// Made by Thalos  01/04/02
// Calle Pobre

inherit "/std/suboscuridad";
#include "../../path.h"

void setup() {

   set_zone("keroon_pobre");
   set_exit_color("cyan");
   set_light(50);
   set_short("%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^BLUE%^: Cruce Calle del asesinato con Avenida de la separacion%^RESET%^");
   set_long("\n%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^BLUE%^: Cruce Calle del asesinato con Avenida de la separacion%^RESET%^.\n\n""Estas en el cruce  de la calle del asesinato con la avenida de la separacion,estas en la zona pobre de Keroon en una callejuela estrecha con muchos lugares sombrios,debe su nombre a que cada cierto tiempo se encuentra el cuerpo sin vida de algun desdichado duergar, las autoridades investigan el asunto aunque no suele llegarse a ninguna conclusion que permita identificar y atrapar a los culpables, otros dicen que el nombre es debido a que por algun lugar de la zona se encuentra un sitio de reunion de asesinos""\n\n");

add_exit("oeste",KEROONPOBRE+"keroon_260.c","standard");
add_exit("norte",KEROONPOBRE+"keroon_234.c","standard");
add_exit("sur",KEROONPOBRE+"keroon_277.c","standard");
}
