// Made by Vulvac 09/11/02

inherit "/std/suboscuridad.c";
#include "../path.h"
void setup() {
set_zone("cultivos");
set_exit_color("green");
set_light(30);	
set_short("%^BOLD%^%^RED%^Cultivos en llamas %^RESET%^");

set_long("\n%^BOLD%^%^RED%^Cultivos en llamas%^RESET%^.\n\nPuedes ver claramente como las llamas consumen este lugar. Ves una mujer en el centro de las llamas pidiendo auxilio. Sabes perfectamente que este incendio ha sido probocado. Te extranya no avistar ningun guardia alrededor de la zona. Si te quedas mucho tiempo podrias perecer en las llamas.\n\n");
add_exit("norte" ,CULTIVOS+"cultivo_38.c","standard");
add_exit("sur" ,CULTIVOS+"cultivo_31.c","standard");

}