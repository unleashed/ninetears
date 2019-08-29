// Sinister & Aokromes

#include "../../path.h"
inherit "/std/room";
void setup() {
   set_light(50);
   set_short("%^BOLD%^%^BLACK%^Torre Negra. Nivel 2.%^RESET%^");
   set_long("Te encuentras en el segundo nivel de la "
   "%^BOLD%^%^BLACK%^Torre Negra%^RESET%^, nada cambia al nivel "
   "anterior, solo cambia tu miedo, alertado por tu subsconciente "
   "el cual te berrea incesantemente...vas a morir. \n"
   "De repente ves que hay unas escaleras, y se te plantea ante "
   "ti una gran duda, seguir o no seguir, sin duda viendo lo anterior, "
   "continuar sera aun mas doloroso que antes.\n");
   
   add_clone(TN"npcs/zombie2",random(2-1));
   
   add_exit("oeste",TN2"tn_b_22","road");
   add_exit("este",TN2"tn_b_20","road");
   set_zone("tn");
}

void init()
{
 ::init();
 add_action("subir_escaleras","subir");
}

int subir_escaleras(string str)
{
  if(str=="escaleras")
  {
   write("Empiezas a ascender por el angosto pasillo que te llevara al "
   "siguiente nivel, el pasillo parece estar rodeado de una neblina "
   "ultraterrenal como si los espiritus de los muertos aguardasen llevarse "
   "tu alma, sientes el dolor indescriptible, mayor que cualquier dolor "
   "sentido desde que entraste a la torre, tal vez sea verdad que Oskuro la "
   "maldijo ya que el dolor parece llegarte hasta tu alma.\n");
   this_player()->adjust_hp(-40);
   say(this_player()->query_cap_name()+" sube la escalera.\n");

   TP->move(load_object(TN3"tn_c_1"));
   return(1);
  }
  notify_fail("Subir que?.\n");
  return(0);
}

void event_enter(object ob, string mensaje, object donde)
{
if (ob->query_player())
{
      if (ob->query_dead())
      {
      write("Por alguna estranya razon una corriente de aire negro te envuelve
"
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

