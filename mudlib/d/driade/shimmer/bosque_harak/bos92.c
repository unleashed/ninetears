/* By Shimmer */

#include "../path.h"

inherit "/std/outside";

void setup() {

   set_exit_color("green");
   set_zone("bosque");
   set_light(50);
   set_short("%^GREEN%^Bosque de %^BOLD%^%^GREEN%^Harak%^RESET%^");
   set_long("%^GREEN%^Bosque de %^BOLD%^%^GREEN%^Harak%^RESET%^\n\n"
   "Te encuentras en el bosque de Harak, es un bosque de arboles jovenes, "
   "altos y llenos de ramas y hojas verdes que forman una espesa capa que "
   "cubre el cielo. Es un sitio humedo y fresco y respirar un aire tan puro "
   "te hace sentir como nuevo. Esta lleno de alimanyas y animalillos, la mayoria "
   "de ellos casi inofensivos.\n\n");

add_clone(NPCS+"varios_bosque_harak.c",random(5));

add_exit("norte",BOSQUEHARAK+"bos93.c","standard");
add_exit("sudeste",BOSQUEHARAK+"bos91.c","standard");

}