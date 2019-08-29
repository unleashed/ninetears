/* By Shimmer */

#define CREATOR "shimmer"

#include "../../path.h"

inherit CLOACASBRE+"cloacasroom.c";

void setup()
{
   base_desc();
   set_exit_color("black");
   set_short("%^BOLD%^BLUE%^Cloacas de Brethem:%^BLACK%^ Tuneles Superiores%^RESET%^");
   long_desc();

   crea_npcs();

   add_exit("este",        CLOACASBRE + "clo42", "corridor");
 

}


void init()
{
   ::init();
   add_action("cloaca", "empuja*r");
   add_action("cloaca", "quita*r");
}

void cloaca(string tapa)
{
   if (!tapa || tapa!="tapa")
   {
      this_player()->notify_fail(query_verb()+" como?\n");
      return 0;
   }
   write("\nEmpujas con todas tus fuerzas la tapa superior que hay en el techo del tunel separandola hacia un lado "
   "dejando via libre hacia la superficie, sin pensartelo pegas un salto y agarrandote al borde subes hacia arriba.\n\n");
   say(this_player()->query_cap_name()+" empuja la tapa metalica del techo y la aparta para luego subir a la superficie de un salto.\n\n");
   this_player()->move(BRETHEM + "bajos26.c");
   this_player()->look_me();
   return 1;
}
