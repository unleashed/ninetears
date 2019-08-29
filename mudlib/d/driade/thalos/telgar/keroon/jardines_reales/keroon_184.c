// Made by Thalos  01/04/02
//jardines reales

#include "../../path.h"

inherit JARDINES+"jardines.c";

void setup() {

   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^CYAN%^Ciudad de %^BLACK%^Keroon%^GREEN%^: Jardines Reales%^RESET%^");
   jardines_desc();

add_exit("oeste",JARDINES+"keroon_183.c","standard");
add_exit("este",JARDINES+"keroon_185.c","standard");
}
