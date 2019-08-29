/* By Shimmer */

#define CREATOR "shimmer";

#include "../../path.h"

inherit BRETHEM + "cityroom.c";


void setup() {

   base_desc();
   set_exit_color("green");
   set_short("%^BOLD%^Ciudad de Brethem : %^BOLD%^GREEN%^Parque del Poeta%^RESET%^");
   set_long("%^BOLD%^Ciudad de Brethem : %^BOLD%^GREEN%^Parque del Poeta%^RESET%^\n\n"
            "Te encuentras en una especie de parque en medio de la ciudad, puedes ver flores, pequenyos estanques "
            "y arboles de todo tipo a tu alrededor cargados de frutos y flores, parece como si fuera un mundo aparte, "
            "que casi pasa desapercibido en medio del agobio y el ajetreo de la ciudad, si te concentras puedes oir el "
            "cantar de los pajaros y el maullar de los gatos que los persiguen de un lado a otro. El parque recibe el "
            "nombre de la leyenda acerca de un antiguo poeta que habitaba en la ciudad y se acercaba siempre a esta "
            "zona a inspirarse y relajarse esperando encontrar las palabras acertadas para sus poesias.\n\n"); 

   add_item(({"flores", "flor", "frutos"}), "Al mirar a tu alrededor llaman tu atencion las preciosas flores y frutos "
              "adornan gran parte de los jardines y arboles del parque desprendiendo un fresco aroma.");
   add_item(({"estanque", "estanques"}), "Varios estanques de agua cristalina rodean el camino que discurre a traves "
              "del parque, al fijarte puedes ver peces de colores nadando de un lado a otro.");
   add_item(({"pez", "peces"}), "Peces de muchos colores nadan de un lado a otro por los estanques del parque.");
   add_item(({"arbol", "arboles"}), "Arboles de varios tipos y tamanyos adoran el parque con sus hojas verdes y sus "
              "llamativas flores y frutos.");

   crea_npcs_parque();

add_exit("oeste",        BRETHEM + "parque9.c","standard");
add_exit("este",         BRETHEM + "mar0.c","standard");
add_exit("sudoeste",     BRETHEM + "parque7.c","standard");

}
