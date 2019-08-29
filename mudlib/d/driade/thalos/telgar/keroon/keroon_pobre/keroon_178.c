// Made by Thalos  01/04/02
// Calle Pobre

inherit "/std/underground";
#include "../../path.h"

void setup() {

   set_zone("keroon_pobre");
   set_exit_color("cyan");
   set_light(50);
   set_short("%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^BLUE%^: Puertas del mercado%^RESET%^");
   set_long("\n%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^BLUE%^: Puertas del mercado^RESET%^.\n\n""Estas delante de dos enormes portalones de madera, lo que es una rareza en los duergars, estan llenos de adornos de cobre asi como de un gran pasador de hierro que cierra las puertas en caso de necesidad.""\n\n");
   add_item(({"adorno","adornos"}),"Son unos bellos adornos realizados en cobre, representado a duergars luchando contra dragones y otros enemigos.\n"); 
add_clone(NPCS+"bixos_keroon_pobre2.c",random(5)); 
add_exit("oeste",MERCADO+"keroon_177.c","standard");
add_exit("este",KEROONPOBRE+"keroon_179.c","standard");
}
