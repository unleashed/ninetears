// Made by Vulvac 09/11/02

inherit "/std/suboscuridad.c";
#include "../path.h"
void setup() {
set_zone("palacio");
set_exit_color("black");
set_light(30);	
set_short("Sala de espera");

set_long("\nSala de espera.\n\nEsta sala esta destinada para acojer a multitud de ciudadanos que a diario vienen para solventar sus asuntos con la administracion de palacio. Es una sala sencilla con muchas sillas.\n\n");
add_item("sillas","Son unas sencillas sillas de madera que usa la gente de Keroon en su larga espera.\n");
add_exit("oeste" ,PALACIO+"palacio_13.c","standard");
}