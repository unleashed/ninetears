// Valar Enero 2003

inherit "/std/suboscuridad.c";
#include "../../path.h"
void setup() {
set_zone("palacio");
set_exit_color("black");
set_light(30);	
set_short("%^BOLD%^Palacio Real: %^CYAN%^Sala de Reuniones%^RESET%^");

set_long("\n%^BOLD%^Palacio Real: %^CYAN%^Sala de Reuniones%^RESET%^.\n\nEsta es la sala donde el rey concede audiencia y donde se discuten los conflictos del reino."
         " Para poder acceder al rey deberas superar a los guardias, cosa que sera facil si no has cometido ningun crimen.\n\n");
         
add_item("antorchas","Ves unas pequenyas antorchas a lo largo y ancho del pasillo, sin ellas no pordias ver por donde caminas.\n");
add_item("armaduras","Ves armaduras de todo tipo, completas , cotas de mallas...etc una gran coleccion.\n");

add_exit("oeste" ,PALACIO+"palacio_112.c","standard");
add_exit("sur" ,PALACIO+"palacio_121.c","standard");

}
