// Made by Thalos  01/04/02
// Calle Pobre

inherit "/std/underground";
#include "../../path.h"

void setup() {

   set_zone("keroon_pobre");
   set_exit_color("cyan");
   set_light(10);
   set_short("%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^BLUE%^: Calle de los tullidos%^RESET%^");
   set_long("\n%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^BLUE%^: Calle de los tullidos%^RESET%^.\n\n""Estas en la calle de los tullido, una de las calles de la zona pobre de Keroon, esta calle recibe su nombre debido a que despues de las terribles luchas que se libraron contra las perfidas razas de la superficie, bajo el reinado de Beltuban I linaje que se mantiene hasta la actualidad en la figura de Gredford III, y de las cuales los duergars fueron abrumadores vencedores asi lo relatan sus cronicas, hubo una multitud de duergars que volvieron tullidos del combate faltandoles un brazo una pierna o las dos cosas, por lo que Beltuban I en agradecimiento a los servicios prestados durante la guerras les regalo un piso en esta calle, asi como una exigua pension de por vida.""\n\n");

add_exit("norte",KEROONPOBRE+"keroon_285.c","standard");
add_exit("sur",KEROONPOBRE+"keroon_318.c","standard");
}
