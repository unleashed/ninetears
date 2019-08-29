/* By Shimmer */

#include "../path.h"

inherit "/std/outside";


void setup() {

   set_exit_color("cyan");
   set_zone("ladera");
   set_light(40);
   set_short("%^GREEN%^Ladera Norte del %^BOLD%^%^BLACK%^Harak-Din%^RESET%^");
   set_long("%^GREEN%^Ladera Norte del %^BOLD%^%^BLACK%^Harak-Din%^RESET%^\n\n"
   "Te encuentras en un sendero que transcurre por la ladera "
   "norte del Harak-Din, el camino es ahora muy empinado y tortuoso, "
   "a los lados la vegetacion es escasa y puedes ver enormes rocas por "
   "todos lados. Un vientro frio y cortante te azota constantemente y te "
   "empieza a costar respirar debido a la altitud en la que te encuentras.\n\n");

add_clone(NPCS+"varios_ladera_harak.c",random(2));

add_exit("sudeste",HARAK+"lad39.c","standard");
add_exit("abajo",HARAK+"lad37.c","standard");
}