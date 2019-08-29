/* By Shimmer */

#include "../path.h"

inherit "/std/outside";

void setup() {

   set_exit_color("cyan");
   set_zone("caminominas");
   set_light(50);
   set_short("%^BOLD%^YELLOW%^Camino a Minas Zhyrkhom%^RESET%^");
   set_long("%^BOLD%^YELLOW%^Camino a Minas Zhyrkhom%^RESET%^\n\n"
   "Estas ya en la meseta de la montanya, donde se encuentra la entrada de la mina, puedes ver "
   "mineros por todos lados realizando su trbajo y a los guardias azotando a los esclavos para que "
   "realicen mas rapido su trabajo, al frente, una gran puerta de metal cubre la entrada a la caverna "
   "principal de la mina.\n\n");

add_clone(NPCS+"guardias_orcos.c",random(1));
add_clone(NPCS+"minero_mina_zhyrkhom.c",random(1));

add_exit("dentro",ZHYRKHOM+"min1.c","standard");
add_exit("este",ZHYRKHOM+"camino_minas7.c","standard");

}