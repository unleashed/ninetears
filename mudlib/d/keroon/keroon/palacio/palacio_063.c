// Valar Enero 2003

inherit "/std/suboscuridad.c";
#include "../../path.h"
void setup() {
set_zone("palacio");
set_exit_color("black");
set_light(30);	
set_short("%^BOLD%^Palacio Real: %^CYAN%^Planta Segunda%^RESET%^");

set_long("\n%^BOLD%^Palacio Real: %^CYAN%^Planta Segunda%^RESET%^.\n\nEsta es la planta de los guardias del castillo. Puedes ver un ir y venir de tropas por todos lados que vigilan fuertemente la planta."
         " En el piso superior se encuentran las estancias del rey y sus personas mas allegadas.\n\n");
         
add_item("antorchas","Ves unas pequenyas antorchas a lo largo y ancho del pasillo, sin ellas no pordias ver por donde caminas.\n");
add_item("armaduras","Ves armaduras de todo tipo, completas , cotas de mallas...etc una gran coleccion.\n");

add_exit("norte" ,PALACIO+"palacio_058.c","standard");
add_exit("sur",PALACIO+"palacio_068.c","standard");

}