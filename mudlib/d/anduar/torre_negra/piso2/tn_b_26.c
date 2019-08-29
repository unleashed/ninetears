// Amorphy

#include "../../path.h"
inherit "/std/room";
void setup() {
   set_light(50);
   set_short("%^BOLD%^%^BLACK%^Torre Negra. Nivel 2.%^RESET%^");
   set_long("Restos humanos... cada paso hacia el interior de la "
   "%^BLACK%^BOLD%^Torre Negra%^RESET%^ te acerca mas a las oscuras "
   "y temidas manos de la muerte. Cadaveres horriblemente mutilados "
   "son tu unica companyia en el angosto corredor en que ahora te "
   "encuentras. Aunque este algo iluminado en este tramo, la luz "
   "que puedes ver es mortecina, palida y debil, arrastrando tras "
   "de si todas tus esperanzas de salir con vida.\n");
   
   add_clone(TN"npcs/zombie2",random(2-1));
   
   add_exit("este",TN2"tn_b_25","road");
   add_exit("sur",TN2"tn_b_27","road");
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
