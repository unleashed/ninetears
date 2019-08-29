// Sinister '99.

#include "../../path.h"
inherit "/std/room";
void setup() {
   set_light(50);
   set_short("%^BOLD%^%^BLACK%^Torre Negra. Nivel 4. Pasillo Central.%^RESET%^");
   set_long("Nada mas subir las ultimas escaleras te encuentras en un pasillo "
   "que parece acceder a una gigantesca biblioteca, por todos lados ves runas "
   "escritas en algun arcano lenguaje, parece elfico, solo que mas antiguo, "
   "pero si los elfos fueron los primeros seres en escribir, quien pudo ser el "
   "autor de esta escritura ancestral? \n");
   add_exit("abajo",TN3"tn_c_17","road");
   add_exit("norte",TN4"tn_d_47","road");
   add_clone(TN"npcs/zombie4",random(2));
   
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
