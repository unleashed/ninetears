// Made by Vulvac 09/11/02

inherit "/std/suboscuridad.c";
#include "../path.h"
void setup() {
set_zone("cultivos");
set_exit_color("green");
set_light(30);	
set_short("%^BOLD%^%^GREEN%^Cultivos subterraneos%^RESET%^");

set_long("\n%^BOLD%^%^GREEN%^Cultivos subterraneos%^RESET%^.\n\nTe encuentras en uno de los muchos cultivos que tiene keroon. Te das cuenta de que no es un tipo de cultivo normal, solo ves setas,hongos,liquenes y alimentos de este tipo. Piensas que sea debido a que la luz del sol no puede entrar en el cultivo. Aunque parece muy tetrico puedes observar que la gente que trabaja en el cultivo esta alegre de hacer lo que hace. No parece que tengan ganas de ser molestados\n\n");
add_clone("/w/vulvac/npcs/agricultor.c",random(3));
add_clone("/w/vulvac/npcs/agricultora.c",random(2));
add_exit("noroeste" ,CULTIVOS+"cultivo_6.c","standard");
add_exit("sudoeste" ,CULTIVOS+"cultivo_4.c","standard");

}






