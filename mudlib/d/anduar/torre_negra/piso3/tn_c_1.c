// Amorphy

#include "../../path.h"
inherit "/std/room";
void setup() {
   set_light(50);
   set_short("%^BOLD%^%^BLACK%^Torre Negra. Nivel 3.%^RESET%^");
   set_long("Dudas que haya muchos mas pisos, ya que habiendo "
   "visto la torre desde fuera, imaginas que como mucho habra "
   "otro mas, pero esa no es la preocupacion que te asalta ahora "
   "mismo, sino que es, que misterios oculta la %^BOLD%^%^BLACK%^"
   "Torre Negra%^RESET%^. \n");
   
   add_clone(TN"npcs/zombie3",random(2-1));
   
   add_exit("abajo",TN2"tn_b_21","road");
   add_exit("este",TN3"tn_c_2","road");
   add_exit("oeste",TN3"tn_c_32","road");
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
