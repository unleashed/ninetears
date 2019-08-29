// Made by Thalos  01/04/02
//jardines reales

#include "../../path.h"

inherit JARDINES+"jardines.c";

void setup() {

   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^CYAN%^Ciudad de %^BLACK%^Keroon%^GREEN%^: Jardines Reales%^RESET%^");
   jardines_desc();
add_clone(NPCSJARDINES+"bixos_jardines.c",random(5)); 

add_exit("norte",JARDINES+"keroon_180.c","standard");
add_exit("sur",JARDINES+"keroon_219.c","standard");
}
