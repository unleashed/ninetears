// Valar Enero 2003

inherit "/std/suboscuridad.c";
#include "../../path.h"
void setup() {
set_zone("palacio");
set_exit_color("black");
set_light(30);	
set_short("%^BOLD%^Palacio Real: %^CYAN%^Trono del Rey%^RESET%^");

set_long("\n%^BOLD%^Palacio Real: %^CYAN%^Trono del Rey%^RESET%^.\n\nEstas en la sala del trono del rey. Deberas mostrarle tu respeto no mostrando actitudes violentas."
         " En el trono se sienta el rey Gredford VIII, el gran y temido guerrero.\n\n");
         
add_item("antorchas","Ves unas pequenyas antorchas a lo largo y ancho del pasillo, sin ellas no pordias ver por donde caminas.\n");
add_item("armaduras","Ves armaduras de todo tipo, completas , cotas de mallas...etc una gran coleccion.\n");
add_item("trono","Ves un trono de piedra en el que se asienta el gran rey Gredford VIII `El Temible�.\n");

add_exit("norte" ,PALACIO+"palacio_139.c","standard");
add_exit("sudeste" ,PALACIO+"palacio_148.c","standard");

}
