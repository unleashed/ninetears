// Made by Thalos  01/04/02
// Calle matones

inherit "/std/suboscuridad";
#include "../../path.h"

void setup() {

   set_exit_color("cyan");
   set_light(10);
   set_short("%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^BLUE%^: Calle de los matones%^RESET%^");
   set_long("\n%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^BLUE%^: Calle de los matones%^RESET%^.\n\n""Estas en un pequenyo  callejon, apenas iluminado, te llama la atencion no ver a ningun duergar por esta zona.Despues de un rato caes en la cuenta de que te encuentras en la calle de los matones, el lugar preferido por estos ultimos para ajustar las cuentas con aquellos que mantiene deudas de algun tipo, si tienes algun problema tal vez puedas contratarlos aunqueresultara caro.""\n\n");

add_exit("norte",KEROONPOBRE+"keroon_65.c","standard");
add_exit("sur",KEROONPOBRE+"keroon_87.c","standard");
}
