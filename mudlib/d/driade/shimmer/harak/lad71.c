/* By Shimmer */

#include "../path.h"

inherit "/std/outside";

void setup() {

   set_exit_color("cyan");
   set_zone("ladera");
   set_light(40);
   set_short("%^GREEN%^Ladera Sur del %^BOLD%^%^BLACK%^Harak-Din%^RESET%^");
   set_long("%^GREEN%^Ladera Sur del %^BOLD%^%^BLACK%^Harak-Din%^RESET%^\n\n"
   "Te encuentras en un sendero que transcurre por la ladera "
   "sur del Harak-Din, el camino es ahora muy empinado y tortuoso, "
   "a los lados la vegetacion es escasa y puedes ver enormes rocas por "
   "todos lados. Un vientro frio y cortante te azota constantemente y te "
   "empieza a costar respirar debido a la altitud en la que te encuentras.\n\n");

add_clone(NPCS+"varios_ladera_harak.c",random(2));


add_exit("sudoeste",HARAK+"lad72.c","standard");
add_exit("este",HARAK+"lad70.c","standard");
}