// Made by Thalos  01/04/02
// Calle Pobre

inherit "/std/suboscuridad";
#include "../../path.h"

void setup() {

   set_zone("keroon_pobre");
   set_exit_color("cyan");
   set_light(50);
   set_short("%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^BLUE%^:Cruce Calle las tabernas con Calle los matones%^RESET%^");
   set_long("\n%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^BLUE%^: Cruce Calle las tabernas con calle los matones%^RESET%^.\n\n""Estas en el cruce calle las tabernas con calle los matones, esta calle esta llena de tabernas debido a que todas las tabernas se concentran en ella, tambien puedes observar varias peleas desatadas sin duda por las bebidas que se sirven en la zona.""\n\n");

add_item(({"pelea","peleas"}),"Ves a varios duergars zurrandose entre ellos, en medio de gritos e insultos, no sabes bien el porque de la pelea pero como no va contigo los dejas en paz.\n"); 

add_exit("oeste",KEROONPOBRE+"keroon_44.c","standard");
add_exit("este",KEROONPOBRE+"keroon_46.c","standard");
add_exit("sur",KEROONPOBRE+"keroon_65.c","standard");
}
