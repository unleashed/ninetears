// Made by Vulvac 09/11/02

inherit "/std/suboscuridad.c";
#include "../path.h"
void setup() {
set_zone("cultivos");
set_exit_color("green");
set_light(30);	
set_short("%^BOLD%^%^ORANGE%^Gruta Foul %^RESET%^");

set_long("\n%^BOLD%^%^ORANGE%^Gruta Foul%^RESET%^.\n\nTe encuentras delante de lo que tu piensas es un ivernadero. Nota como la humedad te envuelve y te rodea. En el poco tiempo que te encuentras en esta gruta, se te estan empezando a mojar todos tus ropajes. Si no sales rapido de aqui seguramente saldras completamente mojado. Puedes ver como el producto que se cultiva sigue siendo hongos, setas y liquines, pero te das cuenta de que en esta pequenya zona hay muchisimos mas que en el resto de cultivos.\n\n");
add_item("hongos","Ves hongos de todo tipo. A simple vista no te parecen algo muy apetitoso pero a las gente de keroon les resulta un manjar.\n");
add_item("setas","Son un tipo de seta muy raro que nunca has visto, tienen la base grande y el extremo de la seta pequenyo. Es de color marron. A simple vista no parece muy buena.\n");
add_item("humedad","La humedad aqui es casi palpable. La gente que trabaja en esta zona esta completamente empapada.\n");
add_clone("/w/vulvac/npcs/agricultor.c",random(3));
add_clone("/w/vulvac/npcs/agricultora.c",random(2));
add_exit("norte" ,CULTIVOS+"cultivo_19.c","standard");
add_exit("sudoeste" ,CULTIVOS+"gruta_17.c","standard");

}