	// Made by Vulvac 09/11/02

inherit "/std/suboscuridad.c";
#include "../path.h"
void setup() {
set_zone("cultivos");
set_exit_color("green");
set_light(30);	
set_short("%^BOLD%^%^ORANGE%^Zona seca%^RESET%^");

set_long("\n%^BOLD%^%^ORANGE%^Zona seca%^RESET%^.\n\nEsta es una zona dedicada al secado de las setas mas especiales que se cultivan en esta zona. Notas como la sequedad aqui es algo extranya ya que muy cerca de aqui hay una zona de cultivos humedos, deduces que han conseguido esta sequedad por unos grandes  trozos de plastico que actuan como invernadero. La zona no es muy grande pero parece suficiente para abastecer a la ciudad de ricos hongos.\n\n");
add_item("plastico","Ves un gran plastico que cubre varias habitaciones de este tipo. El plastico retiene el calor de los cultivos haciendo de esta zona un lugar muy seco y sin humedad. Parece que algun especialista esta al mando de estos cultivos.\n");
add_clone("/w/vulvac/npcs/agricultor.c",random(3));
add_clone("/w/vulvac/npcs/agricultora.c",random(2));
add_exit("norte" ,CULTIVOS+"cultivo_36.c","standard");
add_exit("sur" ,CULTIVOS+"cultivo_33.c","standard");

}