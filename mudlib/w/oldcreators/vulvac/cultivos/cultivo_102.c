// Made by Vulvac 09/11/02

inherit "/std/suboscuridad.c";
#include "../path.h"
void setup() {
set_zone("cultivos");
set_exit_color("green");
set_light(30);	
set_short("%^BOLD%^Sala de pago%^RESET%^");

set_long("\n%^BOLD%^Sala de pago%^RESET%^.\n\nEsta es una sala dedicada especificamente al pago de los trabajadores de los cultivos de Keroon. Ves una gran mesa donde se efectuan los pagos a los trabajadores.\n\n");
add_item("mesa","Ves una gran mesa llena de papeles y con una gran pluma para escribir.\n");
add_exit("noroeste" ,CULTIVOS+"cultivo_2.c","standard");
}