// Made by Vulvac 09/11/02

inherit "/std/suboscuridad.c";
#include "../path.h"
void setup() {
set_zone("cultivos");
set_exit_color("green");
set_light(30);	
set_short("%^ORANGE%^Zona cercada%^RESET%^");

set_long("\n%^ORANGE%^Zona cercada%^RESET%^.\n\nEsta es una de las pocas zonas a las que no se puede acceder en estos cultivos. Una gran barrera de metal impide tu acceso a ella. Puedes ver atraves de la barrera que la zona esta despoblada y parece que en esta zona no crece ningun tipo de alimento.\n\n");
add_item("barrera","Es una gran barrera de metal que te impide el acceso a la zona adyacente. Quizas puedas desplazarla o acceder a la zona por otro sitio.\n");

add_exit("sudoeste" ,CULTIVOS+"cultivo_8.c","standard");

}






