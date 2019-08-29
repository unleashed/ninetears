/* By Shimmer */

#define CREATOR "shimmer"

#include "../../path.h"

inherit BRETHEM+"cityroom.c";

void setup() {
   
   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^Ciudad de Brethem : %^BOLD%^%^RED%^Avenida del Este%^RESET%^");
   set_long("%^BOLD%^Ciudad de Brethem : %^BOLD%^%^RED%^Avenida del Este%^RESET%^\n\n"
            "La Avenida del Este es la via principal de entrada y salida de Brethem hacia el este, es una amplia "
            "calzada bordeada por grandes arboles de ramas finas y cargadas de hojas, por aqui pasan diariamente cientos de "
            "habitantes y viajeros que entran o salen de la ciudad constantemente, asi como los carros cargados de todo tipo de "
            "bienes para vender en el mecado o transportar a otras ciudades.\n\n");

   add_item(({"arbol", "arboles"}), "Grandes y altos arboles de cientos de anyos crecen al lado de la avenida, sus largas y finas "
              "ramas cargadas de hojas verdes colorean el paisaje proporcionando un vistoso paisaje a la via de entrada de la ciudad.");
     
   crea_npcs();

add_exit("oeste",        BRETHEM + "av_este8.c","standard");
add_exit("este",         BRETHEM + "av_este10.c","standard");
add_exit("sur",          BRETHEM + "callejon10.c","standard");


}
