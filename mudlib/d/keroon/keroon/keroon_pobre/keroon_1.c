// Made by Thalos  01/04/02
// Posada

inherit "/std/suboscuridad";
#include "../../path.h"

void setup() {
   
   set_exit_color("cyan");
   set_light(50);
   set_short("%^BOLD%^Habitacion de El enano desmembrado%^RESET%^");
   set_long("\n%^BOLD%^Habitacion de El enano desmembrado%^RESET%^.\n\n""Es una habutacion para los huespedes del establecimineto, aunque por el estado no crees que se queden mucho tiempo, apenas hay un jergon de paja lleno chinches y un armariete para dejar las ropas y demas objetos personales.""\n\n");

add_exit("sur",KEROONPOBRE+"keroon_24.c","standard");
}
