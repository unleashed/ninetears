// Made by Vulvac 09/11/02

inherit "/std/suboscuridad.c";
#include "../path.h"
void setup() {
set_zone("cultivos");
set_exit_color("green");
set_light(30);	
set_short("%^BOLD%^Cultivos%^RESET%^ %^ORANGE%^exoticos%^RESET%^");

set_long("\n%^BOLD%^Cultivos%^RESET%^ %^ORANGE%^exoticos%^%^RESET%^.\n\nNotas como estos cultivos son diferentes a todos los demas que ves por la zona. En esta zona no se cultivan los tipicos hongos y liquenes. Ves una gran variedad de setas con formas exoticas y muy raras. Esta zona esta mas vigilada que las demas por la guardia de Keroon, deduces que es por el valor de los hongos que aqui se cultivan. Estos hongos y setas son los destinados a los mas suculentos platos y comidas de los nobles y gente acomodada de Keroon.\n\n");
add_clone("/w/vulvac/npcs/agricultor.c",random(3));
add_clone("/w/vulvac/npcs/agricultora.c",random(2));
add_exit("noreste" ,CULTIVOS+"cultivo_31.c","standard");
add_exit("oeste" ,CULTIVOS+"cultivo_43.c","standard");

}