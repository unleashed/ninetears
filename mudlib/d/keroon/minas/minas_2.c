// Made by Thalos  26/03/02

inherit "/std/suboscuridad";
#include "../path.h"

void setup() {

   set_zone("minas");
   set_exit_color("yellow");
   set_light(20);
   set_short("%^BOLD%^YELLOW%^Minas de Keeroon%^RESET%^");
   set_long("\n%^BOLD%^YELLOW%^Minas de Keeroon%^RESET%^.\n\n""Tras mucho andar por el corredor acabas por llegar al final del mismo para descubrir un tunel cegado por algun corrimiento de tierra. Te encuentras a varios mineros duergar obervando la zona discutiendo sobre la posible utilidad del corredor o si se debe abandonar definitivamente por su peligro de derrumbe. Asi mismo ves algunos esclavos por la zona, inquietos ante la posibilidad de que se les ordene tener que continuar los sufridos trabajos de desescombro y apertura del corredor.""\n\n");
add_exit("sudoeste",MINAS+"minas_6.c","standard");
}
