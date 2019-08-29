/* By Shimmer */

#define CREATOR "shimmer"

#include "../../path.h"

inherit BRETHEM+"cityroom.c";


void setup() {
   
   base_desc();
   set_exit_color("blue");
   set_short("%^BOLD%^Ciudad de Brethem : %^BOLD%^BLUE%^El Faro%^RESET%^");
   set_long("%^BOLD%^Ciudad de Brethem : %^BOLD%^BLUE%^El Faro%^RESET%^\n\n"
            "Te encuentras en la parte mas saliente del puerto, mas alla de aqui ya solo puedes ver la "
            "inmesidad azul del mar, a la derecha, un enorme edificio de forma tubular se alza inponente "
            "ante ti, y en su parte mas alta puedes ver unas inmensas cristaleras que llaman tu atencion, "
            "te encuentras ante el Faro, utilizado para avisar a las naves y barcos la cercania de los "
            "arricifes y la costa.\n\n");

   crea_npcs_puerto();
   add_clone(BRETHEM+"npcs/guardia",1);

add_exit("oeste",         BRETHEM + "puerto17.c","standard");
add_exit("norte",         BRETHEM + "puerto15.c","standard");
add_exit("puerta",        BRETHEM + "faro1.c","standard");

}
