// Sinister '99.

#include "../../path.h"
inherit "/std/room";
void setup() {
   set_light(50);
   set_short("%^BOLD%^%^BLACK%^Torre Negra. Nivel 4.%^RESET%^");
   set_long("Te encuentras en una habitacion con unos techos de gran altura "
   "quien disenyo esta torre lo hizo para que alguien de gran estatura entrase "
   "en la misma, alguien mas alto que un troll, y por lo visto conocedor de "
   "la magia por el gran volumen de libros escritas en algun arcano lenguaje, "
   "parace elfico, solo que mas antiguo, pero si los elfos fueron los primeros "
   "seres en escribir, quien pudo ser el autor de esta escritura ancestral? \n");
   
 add_clone(BICHOS"ezebhra",1);
      
   add_exit("sur",TN4"tn_d_45","road");
         
set_zone("ent");
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
