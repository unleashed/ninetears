// Sinister '99.

#include "../../path.h"
inherit "/std/room";
void setup() {
   set_light(50);
   set_short("%^BOLD%^%^BLACK%^Torre Negra. Nivel 4. Cuarto de
 Estudio.%^RESET%^");
   set_long("Estas en la habitacion central del cuarto nivel, de esta "
   "inmensa torre, puedes ver montones de libros tirados por todos lados,"
   "pociones con restos de liquidos de los mas diversos colores, todos "
   "llenos de polvo. En las paredes no hay nada mas que estanterias, que "
   "rebosan de frascos llenos de los mas variados componentes de hechizos "
   "y tambien puedes ver lo que deduces seran los libros de magia mas "
   "valiosos de toda la torre, porque tienen todos los bordes recubiertos "
   "de oro y gemas preciosas, estas seguro que ni el mago mas poderoso de "
   "todo el mundo podria llegar a entender jamas las palabras arcanas que "
   "estos contienen. En el centro, un trono de negra Obsidiana, tan grande "
   "que da miedo, con un respaldo de 4 metros de altura, en el centro del "
   "mismo el ojo de Oskuro de nuevo mas bien crecido que tallado, a saber "
   "quien fue el gigante que se sento en este trono, pero no te gustaria "
   "enfrentarte a el.\n");
      
   add_exit("norte",TN4"tn_d_41","road");
   add_exit("noreste",TN4"tn_d_40","road");
   add_exit("este",TN4"tn_d_39","road");
   add_exit("sudeste",TN4"tn_d_38","road");
   add_exit("sur",TN4"tn_d_37","road");
   add_exit("sudoeste",TN4"tn_d_44","road");
   add_exit("oeste",TN4"tn_d_43","road");
   add_exit("noroeste",TN4"tn_d_42","road");     
   set_zone("ent");
   add_clone(TN"npcs/zombiegeneral",1);
}

void init()
{
 ::init();
 add_action("no_rechazar","repeler");
//  add_action("sentarse_trono","sentarse");
}

int sentarse_trono(string str)
{
  if(str=="en trono")
  {
   write("Te sientas en el negro trono de Obsidiana, ahora lo notas, este "
   "trono no fue echo para un mortal si no para el mismisimo Oskuro, senyor "
   "absoluto de la torre tu alma se siente resentida, al notar el poder del "
   "mismo, un trono en el cual las almas mortales sufren, mas alla de lo "
   "indecible.\n");
   this_player()->adjust_gp(-250);
   say(this_player()->query_cap_name()+" se sienta en el trono y desaparece "
   "por algun arte magica.\n");

   TP->move(load_object(TN4"tn_d_1"));
   return(1);
  }
  notify_fail("Sentarse donde?.\n");
  return(0);
}

int no_rechazar(string str)
{
write("Oskuro aparece delante tuyo y dice: Mortal de verdad crees que en mi "
"casa puedes llamar a los dioses para que te ayuden a destruir a mis siervos? "
"\n");
return(1);
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
