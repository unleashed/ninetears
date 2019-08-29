// Made by Vulvac 09/11/02

inherit "/std/suboscuridad.c";
#include "../path.h"
void setup() {
set_zone("palacio");
set_exit_color("black");
set_light(30);	
set_short("%^BOLD%^Palacio Real%^RESET%^");

set_long("\n%^BOLD%^Palacio Real%^RESET%^.\n\nEstas en una de las numerosas salas de este famoso castillo. Este castillo fue construido hace muchos anyos para honrrar a uno de los mas poderosos y sabio reyes Duergars, el rey Pepe. Ves muchas antrochas colgadas de las paredes que iluminan fuertemente el pasillo. Al largo de todo este pasillo ves armaduras colgadas de la pared en forma de decoracion, se dice que esta es una de las colecciones mas grandes del reino. Puedes ver como el castillo es simple de cuatro plantas.\n\n");
add_item("antorchas","Ves unas grandes antorchas a lo largo y ancho del pasillo, sin ellas no pordias ver por donde caminas.\n");
add_item("armaduras","Ves aramaduras de todo tipo, completas , cotas de mallas...etc una gran coleccion.\n");
add_exit("oeste" ,PALACIO+"palacio_1x2.c","standard");
add_exit("este" ,PALACIO+"palacio_1.c","standard");
}