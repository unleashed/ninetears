/* By Shimmer */

#define CREATOR "shimmer"

#include "../../path.h"

inherit "std/room.c";

void setup() {
   
   set_light(50);
   
   set_exit_color("cyan");
   set_short("%^BOLD%^WHITE%^Cuartelillo de la Guardia de Brethem%^RESET%^");
   set_long("%^BOLD%^WHITE%^Cuartelillo de la Guardia de Brethem%^RESET%^\n\n"
            "Un bajo y amplio cuertelillo lleno de estanterias repletas de armas y uniformes se abre "
            "ante tu mirada. Espadas, armaduras, yelmos y demas indumentarias utilizadas por los guardias "
            "llenan la sala. Aqui los guardias descansan en varios bancos de sus rondas y guardan todos sus "
            "instrumentos.\n\n");

   add_item(({"estanteria", "estanterias"}), "Grandes estanterias de madera repletas de armas y armaduras.");
   add_item(({"banco", "bancos"}), "Son largos bancos de madera que los guardias usan para descansar o apoyar sus armas.");

   add_clone(BRETHEM + "npcs/guardia.c", random(7)-1);
   

add_exit("fuera",    BRETHEM + "mied3.c","standard");


}
