// Amorphy

#include "../../path.h"
inherit "/std/room";
void setup() {
   set_light(50);
   set_short("%^BOLD%^%^BLACK%^Torre Negra. Nivel 2.%^RESET%^");
   set_long("Te encuentras en el segundo nivel de la "
   "%^BOLD%^%^BLACK%^Torre Negra%^RESET%^, nada cambia al nivel "
   "anterior, solo cambia tu miedo, alertado por tu subsconciente "
   "el cual te berrea incesantemente...vas a morir. \n"
   "El pasillo vuelve a girar, te das cuenta que lo unico que estas "
   "haciendo es subir mas y mas en lo que parece una carrera la cual "
   "seguramente te llevara a la muerte.\n");
   
   add_clone(TN"npcs/zombie2",random(2-1));
   
   add_exit("oeste",TN2"tn_b_17","road");
   add_exit("sur",TN2"tn_b_15","road");
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
