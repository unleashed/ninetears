// Made by Vulvac 09/11/02

inherit "/std/suboscuridad.c";
#include "../path.h"
void setup() {
set_zone("cultivos");
set_exit_color("green");
set_light(30);	
set_short("%^BOLD%^%^BLACK%^Bifurcacion de caminos%^RESET%^");

set_long("\n%^BOLD%^%^BLACK%^Bifurcacion de caminos%^RESET%^.\n\nEs una sencilla bifurcacion en el camino. Al sur conduce a los cultivos de secano y al sudoeste a la zona de carga. Es un camino ancho, notas que mucha gente lo transita por lo desgastado del suelo.\n\n");
add_clone("/w/vulvac/npcs/agricultor.c",random(3));
add_clone("/w/vulvac/npcs/agricultora.c",random(2));
add_exit("sudoeste" ,CULTIVOS+"cultivo_37.c","standard");
add_exit("sur" ,CULTIVOS+"cultivo_35.c","standard");

}