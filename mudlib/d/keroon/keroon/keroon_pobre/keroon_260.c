// Made by Thalos  01/04/02
inherit "/std/suboscuridad";
#include "../../path.h"

void setup() {

   set_zone("keroon_pobre");
   set_exit_color("cyan");
   set_light(50);
   set_short("%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^BLUE%^: Calle del asesinato%^RESET%^");
   set_long("\n%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^BLUE%^: Calle del asesinato %^RESET%^.\n\n""Estas en la calle del asesinato con la calle de los tullidos,estas en la zona pobre de Keroon en una callejuela estrecha con muchos lugares sombrios,debe su nombre a que cada cierto tiempo se encuentra el cuerpo sin vida de algun desdichado duergar, las autoridades investigan el asunto aunque no suele llegarse a ninguna conclusion que permita identificar y atrapar a los culpables, otros dicen que el nombre es debido a que por algun lugar de la zona se encuentra un sitio de reunion de asesinos""\n\n");

add_exit("oeste",KEROONPOBRE+"keroon_259.c","standard");
add_exit("este",KEROONPOBRE+"keroon_261.c","standard");
}
