// Made by Vulvac 09/11/02

inherit "/std/suboscuridad.c";
#include "../path.h"
void setup() {
set_zone("cultivos");
set_exit_color("green");
set_light(30);	
set_short("%^BOLD%^%^BLACK%^Pasillo oscuro%^RESET%^");

set_long("\n%^BOLD%^%^BLACK%^Pasillo oscuro%^RESET%^.\n\nTe encuentras en un estrecho y oscuro pasillo. Ningun tipo de luz te ilumina el camino. A cada paso que das puedes estar entrando en lo que sea una trampa o tal vez tan solo sea un pasillo sin mas. Oyes ruidos al final del pasillo, mientras caminas notas un olor a podrido y deduces que son restos de comida que hay por el suelo.\n\n");
add_item("restos","Son restos de todo tipo de comidas. Setas, hongos y algunos huesos.\n");
add_item("comida","Son restos de todo tipo de comidas. Setas, hongos y algunos huesos.\n");
add_exit("norte" ,CULTIVOS+"cultivo_61.c","standard");
add_exit("fuera" ,CULTIVOS+"caseta_4.c","standard");
}