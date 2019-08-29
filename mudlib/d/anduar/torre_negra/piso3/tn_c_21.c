// Sinister '99.

#include "../../path.h"
inherit "/std/room";
void setup() {
   set_light(50);
   set_short("%^BOLD%^%^BLACK%^Torre Negra. Nivel 3.%^RESET%^");
   set_long("Este tramo de corredor se encuentra en un deporable "
   "estado. Las paredes, humedas y frias aparecen resquebrejadas en "
   "muchos puntos, a causa del desgaste que han causado anyos de "
   "pura energia maligna transitando por los pasillos. Las piedras "
   "que conforman las paredes tienen aspecto de haber sido pulidas "
   "con una lima, y parecen a punto de desmoronarse en cualquier "
   "momento.\n");
   
   add_clone(TN"npcs/zombie3",random(2-1));
   
   add_exit("este",TN3"tn_c_20","road");
   add_exit("norte",TN3"tn_c_22","road");
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
