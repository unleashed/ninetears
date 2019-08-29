// Amorphy

#include "../../path.h"
inherit "/std/room";
void setup() {
   set_light(50);
   set_short("%^BOLD%^%^BLACK%^Torre Negra. Nivel 1%^RESET%^");
   set_long("Despues de andar por lo que te han parecido horas "
   "y horas por un pasillo aparentemente interminable, "
   "este gira hacia la izquierda, tus animos de encontrar "
   "algo se estan esfumando, como se esfumaron los ancestrales "
   "cuerpos de los que algun dia vivieron en esta fortaleza. \n");
   
   add_clone(TN"npcs/zombie",random(2-1));
   
   add_exit("este",TN1"tn_a_30","road");
   add_exit("norte",TN1"tn_a_32","road");
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
