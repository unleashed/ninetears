/* By Shimmer */

#define CREATOR "shimmer"

#include "../../path.h"

inherit BRETHEM+"cityroom.c";

void setup() {
   
   base_desc();
   set_exit_color("white");
   set_short("%^BOLD%^Ciudad de Brethem : %^BOLD%^%^YELLOW%^Paseo de la Playa%^RESET%^");
   set_long("%^BOLD%^Ciudad de Brethem : %^BOLD%^%^YELLOW%^Paseo de la Playa%^RESET%^\n\n"
            "Estas en el paseo de la playa, una larga calle que bordea la playa situada en plena ciudad "
            "de Brethem. Una pequenya varandilla de metal y madera separa la calzada de una playa de fina y "
            "blanca arena, desde aqui puedes ver como las olas banyan la orilla con un suave ir y venir. Es "
            "una zona tranquila en medio del bullicio de la ciudad. El paseo acaba al este topandose con la "
            "enorme muralla que protege la ciudad.\n\n");

   add_item(({"playa", "arena", "mar", "agua"}), "El mar banya suavemente la playa de arena fina y blanca, "
             "es una vision que t proporciona calma y tranquilidad.");
   add_item("varandilla", "Una larga varandilla que separa la calle de la arena de la playa, es de madera con "
             "barras de metal y apenas se levanta un metro y medio del suelo.");
     
   crea_npcs();

add_exit("oeste",        BRETHEM + "paseoplaya1.c","standard");
add_exit("este",         BRETHEM + "paseoplaya3.c","standard");


}
