/* By Shimmer */

#include "../path.h"

inherit "/std/underground";

void setup() {

   set_exit_color("yellow");
   set_zone("mina");
   set_light(30);
   set_short("%^BOLD%^BLACK%^Minas de %^BOLD%^YELLOW%^Zhyrkhom%^RESET%^");
   set_long("%^BOLD%^BLACK%^Minas de %^BOLD%^YELLOW%^Zhyrkhom%^RESET%^\n\n"
   "Si extiendes los brazos puedes tocar ambas paredes de la mina, estas en un tunel "
   "estrecho, iluminado por antorchas, los mineros ajetreados no paran de moverse y golpear "
   "las paredes con sus picos para extraer el mineral, numerosas vigas de madera por todos "
   "lados soportan el techo para que no se venga abajo.\n\n");

add_clone(NPCS+"varios_mina_zhyrkhom.c",random(2));
add_clone(NPCS+"minero_mina_zhyrkhom.c",random(2));

add_exit("noreste",ZHYRKHOM+"min23.c","standard");
add_exit("sur",ZHYRKHOM+"min25.c","standard");

}