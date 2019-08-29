// Made by Thalos  01/04/02
// Calle Pobre

inherit "/std/suboscuridad";
#include "../../path.h"

void setup() {

   set_zone("keroon_pobre");
   set_exit_color("cyan");
   set_light(10);
   set_short("%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^BLUE%^: Cruce Calle de los tullidos con Calle del suicidio%^RESET%^");
   set_long("\n%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^BLUE%^: Cruce Calle de los tullidos con Calle del suicidio%^RESET%^.\n\n""Estas en el cruce de la calle de los tullidos con la calle del suicidio, una de las calles de la zona pobre de Keroon, esta calle recibe su nombre debido a que despues de las terribles luchas que se libraron contra las perfidas razas de la superficie, bajo el reinado de Beltuban I linaje que se mantiene hasta la actualidad en la figura de Gredford III, y de las cuales los duergars fueron abrumadores vencedores asi lo relatan sus cronicas, hubo una multitud de duergars que volvieron tullidos del combate faltandoles un brazo una pierna o las dos cosas, por lo que Beltuban I en agradecimiento a los servicios prestados durante la guerras les regalo un piso en esta calle, asi como una exigua pension de por vida.""\n\n");
add_clone(NPCSKEROONPOBRE+"bixos_keroon_pobre2.c",random(5)); 
add_exit("norte",KEROONPOBRE+"keroon_340.c","standard");
add_exit("este",KEROONPOBRE+"keroon_361.c","standard");
add_exit("sur",KEROONPOBRE+"keroon_382.c","standard");
}