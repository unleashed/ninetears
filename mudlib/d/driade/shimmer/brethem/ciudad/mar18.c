/* By Shimmer */

#include "../../path.h"

inherit BRETHEM+"cityroom.c";


void setup() {
   
   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^Ciudad de Brethem : Cruce en la %^BOLD%^BLUE%^Calle del Mar%^RESET%^");
   set_long("%^BOLD%^Ciudad de Brethem : Cruce en la %^BOLD%^BLUE%^Calle del Mar%^RESET%^\n\n"
           "Te encuentras en un cruce con cuatro posibles direcciones, cada una desemboca en una calle "
           "distinta, al oeste se encuentra el Mercado de Brethem, lugar en el que es posible comprar o "
           "vender casi cualquier cosa. Al noreste puedes ver como la calle sube hasta lo que parece un gran "
           "conjunto de casas apelotonadas, los barrios bajos. Al sur se encuentra el puerto de la ciudad, con "
           "el rompeolas y los pescadores ajetreados montando los aparejos. Por ultimo al noreste continua la "
           "calle del Mar hasta el otro extremo de la ciudad.\n\n");

   crea_npcs_callemar();

add_exit("sur",         BRETHEM + "mar19.c","standard");
add_exit("noreste",     BRETHEM + "mar17.c","standard");
add_exit("oeste",       BRETHEM + "mercado1.c","standard");
add_exit("noroeste",    BRETHEM + "callejon3.c","standard");


}
