// Sinister '99.

#include "../../path.h"
inherit "/std/room";
void setup() {
   set_light(50);
   set_short("%^BOLD%^%^BLACK%^Torre Negra. Nivel 3.%^RESET%^");
   set_long("Ante ti el que crees ya, la subida al ultimo piso, bloqueada por "
   "una gigantesca puerta de la mas negra obsidiana jamas vista, en el centro "
   "de la misma un gigantesco simbolo de Oskuro parece como si fuese parte de "
   "la misma obsidiana, ya que no esta tallado ni dibujado, como si hubiese "
   "sido el mismisimo Oskuro el que hubiese hecho que la obsidiana lo formase,"
   " tu corazon parece que vaya a salirse del pecho. \n");
   add_item("simbolo","Es un simbolo de negra obsidiana, no esta tallado ni "
   "dibujado, pero sin embargo tiene algo raro, parece tangible, a pesar de "
   "no tener relieve.\n");
   
   add_clone(TN"npcs/zombie3",random(2-1));
   
   add_exit("este",TN3"tn_c_16","road");
   add_exit("oeste",TN3"tn_c_18","road");

   set_zone("tn");
}
   
void init()
{
 ::init();
 add_action("girar_simbolo","girar");
}

int girar_simbolo(string str)
{
  if(str=="simbolo")
  {

   write("Tocas el simbolo de Oskuro con la mano, la misma realidad parece "
   "evaporarse, el tiempo parece congelarse, sientes que Oskuro esta aqui, "
   "que el mal emana de las mismas rocas de la torre, que el bien aqui jamas "
   "podra prevalecer, el dolor que sientes es infinito, nunca sentiste algo "
   "asi, hasta tu alma se siente resentida por el increible mal que alberga "
   "este lugar.\n");
   this_player()->adjust_hp(-50);
   this_player()->adjust_gp(-50);
   say(this_player()->query_cap_name()+" gira el simbolo y grita de dolor, "
   "mientras desaparece.\n");

   TP->move(load_object(TN4"tn_d_1"));
   return(1);
  }
  notify_fail("Girar que?.\n");
  return(0);
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
