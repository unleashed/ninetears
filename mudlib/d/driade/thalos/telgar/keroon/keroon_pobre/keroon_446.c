// Made by Thalos  01/04/02
// Calle Pobre

inherit "/std/underground";
#include "../../path.h"

void setup() {

   set_zone("keroon_pobre");
   set_exit_color("cyan");
   set_light(50);
   set_short("%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^BLUE%^: Calle del patibulo%^RESET%^");
   set_long("\n%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^BLUE%^: Calle del patibulo%^RESET%^.\n\n""Estas en una de las calles de la zona pobre de Keroon, la calle del patibulo es una de la mas famosas debido a queal final de ella se encuentra la plaza del patibulo la unica que proporciona un poco de diversion y entretenimiento, en el hastio de la vida de los duergars. En esta calle es donde se cuelga o castiga a los criminales, dependiendo del castigo que dicte el tribunal de justicia duergar, al final del callejon observas la figura del patibulo y algunos cepos. Tambien observas que no te gustaria verte en la piel del criminal debido a que por la longitud y estrechez de la calle unos pocos guardias sirven para evitar cualquier intento de fuga.""\n\n");
add_clone(NPCS+"bixos_keroon_pobre2.c",random(5)); 
add_exit("oeste",KEROONPOBRE+"keroon_445.c","standard");
add_exit("este",KEROONPOBRE+"keroon_447.c","standard");
}
