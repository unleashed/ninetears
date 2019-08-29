// Made by Thalos  01/04/02
// Calle Pobre

inherit "/std/underground";
#include "../../path.h"

void setup() {

   set_zone("keroon_pobre");
   set_exit_color("cyan");
   set_light(50);
   set_short("%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^BLUE%^: Puertas de las forjas%^RESET%^");
   set_long("\n%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^BLUE%^: Puertas de las forjas%^RESET%^.\n\n""Estas delante de las puertas de las forjas, aqui es donde los duergars traen el material que consiguen con gran esfuerzo en las minas y lo funden para conseguir los metales necesarios para la realizacion de sus bellos trabajos, el calor que sale del interior es insufrible pero supones que ello es debido a los grandes fuegos necesarios para que el metal alcance la temperatura de fundicion.""\n\n");
add_item(({"puerta","puertas"}),"Son unas inmensas puertas de piedra, supones que son asi debido a que si fueran de otros materiales podrian verse afectadas por el calor que se desprende del interior.\n"); 

add_exit("norte",KEROONPOBRE+"keroon_382.c","standard");
add_exit("este",FORJAS+"keroon_403.c","standard");
}
