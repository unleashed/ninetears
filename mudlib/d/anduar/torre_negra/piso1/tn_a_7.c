// Amorphy

#include "../../path.h"
inherit "/std/room";
void setup() {
   set_light(50);
   set_short("%^BOLD%^%^BLACK%^Torre Negra. Nivel 1%^RESET%^");
   set_long("Estas en uno de los niveles que componen la fortaleza conocida "
   "como %^BOLD%^%^BLACK%^La Torre Negra%^RESET%^, una ancestral construccion "
   "de origen desconocido, aunque viejas leyendas elficas aseguran que fue "
   "levantada por el mismisimo Oskuro.\n "
   "Oyes lamentos que te parece provienen de las paredes, fundiendose con el "
   "suelo y el techo, y si te paras a escuchar, puedes apreciar una voz que "
   "no es muy humana, gritando en palabras que no puedes reconocer.\n");
   add_clone(TN"npcs/zombie",random(2-1));
   add_exit("oeste",TN1"tn_a_6","road");
   add_exit("sur",TN1"tn_a_8","road");
   set_zone("tn");
}


void event_enter(object ob, string mensaje, object donde)
{
if (ob->query_player())
{
      if (ob->query_dead())
      {
      write("Por alguna estranya razon una corriente de aire negro te envuelve "
      "sientes como el frio congela tu alma, en tu cerebro escuchas a Oskuro "
      "diciendo: No entraras aqui sin pagarme tributo, por lo tanto vuelve "
      "VIVO.\n");
      tell_room(environment(TP),TP->query_cap_name()+" desaparece envuelto "
      "por un aire negro.\n",TP);
      ob->move(load_object(ANDUAR+"cruce1313.c"));
      this_player()->look_me();
      tell_room(environment(TP),TP->query_cap_name()+" aparece envuelto "
      "por un aire negro.\n",TP);
      }
      else
      {

      }
   }
}/*event_enter*/
