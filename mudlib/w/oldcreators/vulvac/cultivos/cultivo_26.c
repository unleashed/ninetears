// Made by Vulvac 09/11/02

inherit "/std/suboscuridad.c";
#include "../path.h"
void setup() {
set_zone("cultivos");
set_exit_color("green");
set_light(30);	
set_short("%^BOLD%^%^BLUE%^Cultivos humedos%^RESET%^");

set_long("\n%^BOLD%^%^BLUE%^Cultivos humedos%^RESET%^.\n\nCada paso que das hacia el interior de estos cultivos te resulta mas dificil ver. Aqui la iluminacion es practicamente nula, no comprendes como los agricultores y agricultoras que trabajan aqui, pueden ver los productos que recolectan. Puedes ver unas especies de caretillas. El aire aqui es frio y no invita a quedarse por mucho tiempo.\n\n");
add_item("carretilla","Tienes delante de ti una especie de carro de metal. Parece ser que usan estos carros como sistema para transportar los liquenes, setas y demas hongos.\n");
add_clone("/w/vulvac/npcs/agricultor.c",random(3));
add_clone("/w/vulvac/npcs/agricultora.c",random(2));
add_exit("norte" ,CULTIVOS+"cultivo_27.c","standard");
add_exit("este" ,CULTIVOS+"cultivo_25.c","standard");

}