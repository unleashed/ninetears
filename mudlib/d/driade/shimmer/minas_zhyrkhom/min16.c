/* By Shimmer */

#include "../path.h"

inherit "/std/underground";

void setup() {

   set_exit_color("yellow");
   set_zone("mina");
   set_light(30);
   set_short("%^BOLD%^BLACK%^Minas de %^BOLD%^YELLOW%^Zhyrkhom%^RESET%^");
   set_long("%^BOLD%^BLACK%^Minas de %^BOLD%^YELLOW%^Zhyrkhom%^RESET%^\n\n"
   "Te encuentras en uno de los tuneles de las Minas Zhyrhom, el tunel es amplio "
   "y esta bien iluminado, hay antorchas en la pared de toda la mina. Puedes ver "
   "como las paredes fueron excavadas en la roca para obtener algun tipo de material, "
   "y numerosas vigas de madera por todos lados soportando el techo para que no se venga abajo.\n\n");

add_clone(NPCS+"varios_mina_zhyrkhom.c",random(2));
add_clone(NPCS+"minero_mina_zhyrkhom.c",random(2));

add_exit("norte",ZHYRKHOM+"min28.c","standard");
add_exit("oeste",ZHYRKHOM+"min27.c","standard");
add_exit("sudoeste",ZHYRKHOM+"min35.c","standard");
add_exit("sudeste",ZHYRKHOM+"min15.c","standard");
add_exit("este",ZHYRKHOM+"min17.c","standard");

}