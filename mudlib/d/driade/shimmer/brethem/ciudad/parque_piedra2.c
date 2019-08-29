/* By Shimmer */

#define CREATOR "shimmer"

#include "../../path.h"

inherit BRETHEM+"cityroom.c";

void setup() {

   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^Ciudad de Brethem : %^BOLD%^GREEN%^Parque de la Piedra%^RESET%^");
   set_long("%^BOLD%^Ciudad de Brethem : %^BOLD%^GREEN%^Parque de la Piedra%^RESET%^\n\n"
            "Te encuentras en un pequenyo parque rodeado de una gran verja de metal, algunos "
            "jardincillos descuidados y casi muertos ocupan los lados, un par de bancos uno en "
            "frente del otro decoran un paisaje casi tetrico, parece que por aqui no pasan mas que "
            "algunos pobres a dormir sus borracheras en alguno de los bancos. En el centro del parque "
            "puedes ver lo que parece una gran roca ovalada incrustada en la tierra.\n\n");
  
   add_clone(BRETHEM + "npcs/borracho",random(2)-1);  
   add_clone(BRETHEM + "npcs/perro",random(2)-1); 
   add_clone(BRETHEM + "npcs/ciudadano",random(2)-1); 


add_exit("sudoeste",        BRETHEM + "parque_piedra3.c","standard");
add_exit("sur",             BRETHEM + "parque_piedra1.c","standard");


}
