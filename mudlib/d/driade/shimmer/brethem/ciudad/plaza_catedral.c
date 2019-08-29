/* By Shimmer */

#define CREATOR "shimmer"

#include "../../path.h"

inherit BRETHEM+"cityroom.c";


void setup() {

   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^Ciudad de Brethem : %^BOLD%^RED%^Plaza de la Catedral%^RESET%^");
   set_long("%^BOLD%^Ciudad de Brethem : %^BOLD%^RED%^Plaza de la Catedral%^RESET%^\n\n"
            "En esta plaza se encuentra la Catedral de Brethem, una enorme construccion de piedra "
            "blanca y brillante, decorada con altas columnas cargadas de simbolos y criaturas antiguas "
            "a los lados de una gran puerta de madera con refuerzos de metal, sobre la puerta grandes "
            "cristaleras de colores tambien decoradas con grabados llaman la atencion por su delicadeza "
            "y belleza a la vez. Una extranya fuerza te invita a entrar y contemplar tal maravilla de la "
            "arquitectura.\n\n");


   add_clone(BRETHEM+"npcs/guardia.c",random(2));   
   add_clone(BRETHEM+"npcs/sacerdote.c",random(2));  


add_exit("sur",          BRETHEM + "gen16.c","standard");
add_exit("dentro",       BRETHEM + "catedral1.c","standard");


}
