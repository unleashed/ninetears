/* By Shimmer */

#define CREATOR "shimmer"

#include "../../path.h"

inherit BRETHEM+"cityroom.c";

void setup() {
   
   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^Ciudad de Brethem : %^BOLD%^%^YELLOW%^Calle de la Arena%^RESET%^");
   set_long("%^BOLD%^Ciudad de Brethem : %^BOLD%^%^YELLOW%^Calle de la Arena%^RESET%^\n\n"
            "Esta pequenya calle une el Paseo de la Playa con la Avenida del Este, al sur el Paseo la separa "
            "de la playa, pero por culpa del fuerte viento la arena llega hasta aqui inundando el suelo, de ahi el "
            "nombre de esta calle. Algunas casitas de varios pisos con sus ventanas apuntando al mar y otras de "
            "planta baja son los unicos edificios que puedes ver.\n\n");

   add_item("arena", "Una fina y blanca arena cubre esta calle metiendosete entre los dedos de los pies y haciendote cosquillas.");
     
   crea_npcs();

add_exit("norte",        BRETHEM + "arena2.c","standard");
add_exit("este",         BRETHEM + "arena4.c","standard");
add_exit("oeste",        BRETHEM + "arena6.c","standard");


}
