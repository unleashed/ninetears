// Valar Enero 2003

inherit "/std/suboscuridad.c";
#include "../../path.h"
void setup() {
set_zone("palacio");
set_exit_color("black");
set_light(30);	
set_short("%^BOLD%^Palacio Real: %^CYAN%^Torres%^RESET%^");

set_long("\n%^BOLD%^Palacio Real: %^CYAN%^Torres%^RESET%^.\n\n" 
         "Te encuentras en el torreon del palacio. Desde aqui se puede divisar todo el reino y "
	 "tener controlados los movimientos de la ciudad. Las "
	 "torres estan construidas en dura piedra y porporcionan una fuerte defensa.\n\n");
         
add_item("antorchas","Ves unas pequenyas antorchas a lo largo y ancho del pasillo, sin ellas no pordias ver por donde caminas.\n");
add_item("armaduras","Ves armaduras de todo tipo, completas , cotas de mallas...etc una gran coleccion.\n");

add_exit("este" ,PALACIO+"palacio_096.c","standard");
add_exit("oeste",PALACIO+"palacio_094.c","standard");

}