// Made by Thalos  01/04/02
// Calle Pobre

inherit "/std/underground";
#include "../../path.h"

void setup() {

   set_exit_color("cyan");
   set_light(50);
   set_short("%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^BLUE%^: Calle de los prestamistas%^RESET%^");
   set_long("\n%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^BLUE%^: Calle de los prestamistas%^RESET%^.\n\n""Estas en la calle de los prestamistas,en la zona pobre de Keroon, en esta calle solian reunirse los prestamistas para hacer sus negocios, pero hace unas decadas uno de ellos considero que no necesitaba competencia por lo que contrato a los matones de la zona y se quedo con el negocio.""\n\n");
add_clone(NPCS+"bixos_keroon_pobre.c",random(5));
add_exit("norte",KEROONPOBRE+"keroon_66.c","standard");
add_exit("sur",KEROONPOBRE+"keroon_88.c","standard");
}
