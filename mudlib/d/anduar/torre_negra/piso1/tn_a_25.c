// Sinister & Aokromes

#include "../../path.h"
inherit "/std/room";
void setup() {
   set_light(50);
   set_short("%^BOLD%^%^BLACK%^Torre Negra. Nivel 1%^RESET%^");
   set_long("Estas en uno de los niveles que componen la fortaleza conocida "
   "como %^BOLD%^%^BLACK%^La Torre Negra%^RESET%^, una ancestral construccion "
   "de origen desconocido, aunque viejas leyendas elficas aseguran que fue "
   "levantada por el mismisimo Oskuro. "
   "Mientras estavas tanteando la pared, para saber si el pasillo seguia, "
   "te das cuenta que hay una especie de escaleras que suben sin parecer "
   "tener fin, hacia lo que supones sera el siguiente nivel de la Torre. \n");
   
   add_clone(TN"npcs/zombie",random(2-1));
   add_exit("este",TN1"tn_a_24","road");
   add_exit("oeste",TN1"tn_a_26","road");
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
   "siguiente nivel, el pasillo tiene calaveras talladas, o tal vez no, por "
   "todos lados segun vas ascendiendo, te das cuenta que las mismas no estan "
   "talladas, si no que son naturales, cientos, tal vez miles de craneos de "
   "todas las razas de los reinos aparecen en las paredes, algunas que no "
   "logras determinar, tal vez desaparecidas hace largo tiempo, incluso "
   "alguna parece ser de algun poder sobreterrenal.\n");
   this_player()->adjust_hp(-20);
   say(this_player()->query_cap_name()+" sube la escalera.\n");

   TP->move(load_object(TN2"tn_b_1"));
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
