// Made by Vulvac 09/11/02

inherit "/std/suboscuridad.c";
#include "../path.h"
void setup() {
set_zone("cultivos");
set_exit_color("green");
set_light(30);	
set_short("Zona de %^CYAN%^carga%^RESET%^");

set_long("\nZona de %^CYAN%^carga%^RESET%^.\n\nEn este lugar se cargan todos los liquenes y hongos recolectados para poder ser administrados a la ciudad de keroon. Mucha de la gente que ves aqui son los agricultores de la zona, pero tambien ves algun que otro cliente impaciente que viene a comprar los hogos y liquines al mismo cultivo, sacando mas a menor precio. Puedes ver una gra balanza.\n\n");
add_item("balanza","Es una gran balanza usada para pesar los sacos de liquenes y hongos.\n");
add_clone("/w/vulvac/npcs/agricultor.c",random(3));
add_clone("/w/vulvac/npcs/agricultora.c",random(2));
add_exit("noreste" ,CULTIVOS+"cultivo_38.c","standard");
add_exit("noroeste" ,CULTIVOS+"cultivo_40.c","standard");

}