// Made by Vulvac 09/11/02

inherit "/std/suboscuridad.c";
#include "../path.h"
void setup() {
set_zone("palacio");
set_exit_color("black");
set_light(30);	
set_short("%^ORANGE%^Administracion Real%^RESET%^");

set_long("\n%^ORANGE%^Administracion Real%^RESET%^.\n\nVes una sala bastante mas pequenya de lo que aparenta, quizas sea por la gran cantidad de papeles que se enceuntran por toda la sala, a lo largo de la cual puedes ver unos cuantos escribas que se mueven atareadamente. Este lugar es donde se saldan las cuentas economicas con el Rey. Puedes ver varias mesas con sus correspondientes tinteros y plumas. El caos parece reinar aqui.\n\n");
add_item("mesas","Son unas pequenyas mesas que los escribas usan para trabajar.\n");
add_item("papeles","Papeles sobre todo tipo de tratos y pagos no parece que haya nada interesante.\n");
add_exit("norte" ,PALACIO+"palacio_8.c","standard");
}