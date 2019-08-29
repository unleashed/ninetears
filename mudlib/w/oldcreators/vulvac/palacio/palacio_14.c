// Made by Vulvac 09/11/02

inherit "/std/suboscuridad.c";
#include "../path.h"
void setup() {
set_zone("palacio");
set_exit_color("black");
set_light(30);	
set_short("%^BOLD%^Palacio Real%^RESET%^");

set_long("\n%^BOLD%^Palacio Real%^RESET%^.\n\nEstas en una de las numerosas salas de este famoso castillo. Este castillo fue construido hace muchos anyos para honrar a uno de los mas poderosos y sabios reyes Duergars, el Rey Zhorthor. Unas pequenyas antorchas iluminan los pasillos de este magnifico palacio. Puedes ver colgados de las paredes unos grandes mosaicos con los anteriores reyes de Keroon.\n\n");
add_item("antorchas","Ves unas grandes antorchas a lo largo y ancho del pasillo, sin ellas no pordias ver por donde caminas.\n");
add_item("mosacios","Son unos viejos mosaicos dedicados a los mas poderosos reyes de Keroon.\n");
add_exit("norte" ,PALACIO+"palacio_13.c","standard");
add_exit("sur" ,PALACIO+"palacio_16.c","standard");
}