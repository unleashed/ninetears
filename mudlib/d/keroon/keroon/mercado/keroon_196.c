// Made by Thalos  01/04/02
// Mercado

#include "../../path.h"
inherit MERCADO+"mercado.c";
void setup() {

   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^RED%^: Mercado%^RESET%^");
   long_desc_mercado();
   add_clone(MERCADONPCS+"bixos_mercado.c",random(5)); 
   
add_exit("oeste",MERCADO+"keroon_195.c","standard");
add_exit("norte",MERCADO+"keroon_175.c","standard");
add_exit("este",MERCADO+"keroon_197.c","standard");
add_exit("sur","/d/keroon/keroon/mercado/local_abandonado.c","standard");
}
