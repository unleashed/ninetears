// Made by Vulvac 09/11/02

inherit "/std/suboscuridad.c";
#include "../path.h"
void setup() {
set_zone("palacio");
set_exit_color("black");
set_light(30);	
set_short("%^BOLD%^Pasillo real%^RESET%^");

set_long("\n%^BOLD%^Pasillo Real%^RESET%^.\n\nEstas en una de las numerosas salas de este famoso castillo. Este castillo fue construido hace muchos anyos para honrar a uno de los mas poderosos y sabios reyes Duergars, el Rey Zhorthor. La iluminacion en esta sala es mayor a la de la sala superior e inferior. Puedes ver como este nivel del castillo esta claramente dedicado al disfrute de los nobles y gente de palacio. Ves salas de juego, comedores y un gran numero de salas de diversion.\n\n");
add_item("salas","Ves muchas salas diferentes, desde un gran comedor, hasta un pequenyo teatro.\n");
add_exit("norte" ,PALACIO+"palacio_25.c","standard");
add_exit("sur" ,PALACIO+"palacio_23.c","standard");
}