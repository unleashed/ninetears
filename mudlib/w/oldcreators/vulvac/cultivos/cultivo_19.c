// Made by Vulvac 09/11/02

inherit "/std/suboscuridad.c";
#include "../path.h"
void setup() {
set_zone("cultivos");
set_exit_color("green");
set_light(30);	
set_short("%^GREEN%^Cultivos profundos%^RESET%^");

set_long("\n%^GREEN%^Cultivos profundos%^RESET%^.\n\nCada vez te adentras mas en los cultivos. Aqui ves como la zona es mucho mas humeda y por lo tanto mejor para el cultivo de estos alimentos. Te das cuenta de que en esta zona trabaja mucha mas gente que en las zonas anteriores. Parece ser que esta zona esta reserbada para la comida de los maximos madatarios de keroon. Te extranya que los guardias te hayan dejado pasar.\n\n");
add_item("hongos","Ves hongos de todo tipo. A simple vista no te parecen algo muy apetitoso pero a las gente de keroon les resulta un manjar.\n");
add_item("setas","Son un tipo de seta muy raro que nunca has visto, tienen la base grande y el extremo de la seta pequenyo. Es de color marron. A simple vista no parece muy buena.\n");
add_clone("/w/vulvac/npcs/agricultor.c",random(3));
add_clone("/w/vulvac/npcs/agricultora.c",random(2));
add_exit("sur" ,CULTIVOS+"gruta_18.c","standard");
add_exit("norte" ,CULTIVOS+"cultivo_15.c","standard");


}