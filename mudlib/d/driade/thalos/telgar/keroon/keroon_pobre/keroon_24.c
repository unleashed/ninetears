// Made by Thalos  01/04/02
// Posada

inherit "/std/underground";
#include "../../path.h"

void setup() {

   set_exit_color("cyan");
   set_light(50);
   set_short("%^BOLD%^Pasillo de El enano desmembrado%^RESET%^");
   set_long("\n^BOLD%^Pasillo de El enano desmembrado%^RESET%^.\n\n""Es en el corredor que conduce a las habitaciones, la verdad es que le haria falta un buen lavado al suelo y las paredes, pero eso no parece importarles a ninguno de los huespedes.""\n\n");

add_exit("oeste",KEROONPOBRE+"keroon_23.c","standard");
add_exit("norte",KEROONPOBRE+"keroon_1.c","standard");
add_exit("este",KEROONPOBRE+"keroon_25.c","standard");
}
