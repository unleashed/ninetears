// Made by Vulvac 09/11/02

inherit "/std/suboscuridad.c";
#include "../path.h"
void setup() {
set_zone("palacio");
set_exit_color("black");
set_light(30);	
set_short("%^BOLD%^%^BLUE%^Estancias de la guardia%^RESET%^");

set_long("\n%^BOLD%^%^BLUE%^Estancias de la guardia%^RESET%^.\n\nEstas en una pequenya sala dedicada al reposo de la guardia del rey. Puedes ver una pequenya mesa con cuatro sillas dispuesta en forma redonda. Puedes ver al fondo de la estancia unos pequenyos camostros para el reposo de la guardia.\n\n");
add_item("camastros","Ves unos pequenyos camastros.\n");
add_item("mesa","Es una mesa pequenya de madera con forma redonda.\n");
add_exit("este" ,PALACIO+"palacio_3.c","standard");
}