// Amorphy

#include "../../path.h"
inherit "/std/room";
void setup() {
   set_light(50);
   set_short("%^BOLD%^%^BLACK%^Torre Negra. Nivel 1%^RESET%^");
   set_long("Tras ascender por un empinado camino, llegas a lo que es la "
   "fortaleza, una inmensa torre de basalto negro, en lo alto de las murallas "
   "observas unas inmensas estatuas de piedra de unos seres de aspecto "
   "humanoide y gran estatura. \n");
   add_clone(TN"npcs/zombie",1);
   add_exit("abajo",TN"tn_9","road");
   add_exit("este",TN1"tn_a_2","road");
   add_exit("oeste",TN1"tn_a_48","road");
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
