/* By Shimmer */

#define CREATOR "shimmer"

#include "../../path.h"

inherit BRETHEM+"cityroom.c";


void setup() {

   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^Ciudad de Brethem : %^BOLD%^MAGENTA%^Barrios Bajos%^RESET%^");
   long_desc_barrios_bajos();

   crea_npcs_barrios_bajos();

add_exit("este",       BRETHEM + "bajos27.c","standard");
add_exit("oeste",      BRETHEM + "bajos25.c","standard");
add_exit("sur",        BRETHEM + "bajos23.c","standard");

}

void init()
{
   ::init();
   add_action("cloaca", "levanta*r");
   add_action("cloaca", "quita*r");
}

void cloaca(string tapa)
{
   if (!tapa || tapa!="tapa")
   {
      this_player()->notify_fail(query_verb()+" como?\n");
      return 0;
   }
   write("\nTe agachas con cuidado para levantar la tapa metalica que conduce a las cloacas de la ciudad, una vez "
   "abierta te deslizas dentro del agujero tapando denuevo la salida. Ante ti se abren las oscuras y sucias cloacas de Brethem.\n\n");
   say(this_player()->query_cap_name()+" levanta algo con ciudado y se "
   "desliza por un agujero dejandote atonito.\n\n");
   this_player()->move(CLOACASBRE + "clo43.c");
   this_player()->look_me();
   return 1;
}
