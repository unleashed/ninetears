// Errante ene 1998 "Descripciones por Virus '98" Testeado y modificado para 
// que funcione por Spp ENE'98 Quitado de describe por Aokromes SEP'99
#include "../path.h"
inherit "/std/underground.c"; // Outside unas Cloacas???

void event_enter(object ob, string mensaje, object donde)
{
  if (interactive(ob) && !(int)ob->query_timed_property("asfixia"))
  {
       switch(ob->query_race_ob())
      {
       case("duergar"):case("enano"):case("drow"):
        tell_room(ob,"No puedes respirar bien.\n");
        ob->adjust_hp(-roll(1,6), this_player());
        ob->add_timed_property("asfixia", 1, TEMP); 
        break;
       default:
        tell_room(ob,"No puedes respirar bien.\n");
        ob->adjust_hp(-roll(2,6), this_player());
        ob->add_timed_property("asfixia", 1, TEMP);
      }
  }
  
} 
void setup()
{
set_short("%^BLUE%^Cloacas nivel 2%^RESET%^");
set_long("El agua cenagosa corre libremente bajo tus pies si ningun "
"tipo de intrusion, aunque de vez en cuando sientes unos pequenyos "
"golpecitos en los pies de los cuales no sabes nada, piensas que "
"seran ratas muertas o algo asi. Las paredes, resbaladizas como "
"siempre pero hay un hueco en la pared en donde no hay moho, en "
"su lugar hay una mancha negra de lo que parece ser carbon. "
"Del techo cuelgan hileras de sal bastante largas, pero algunas "
"estan rotas y yacen clavadas en el fango de los lados del "
 "riachuelo. Se respira mal aqui. Estas perdido.\n");


add_item("paredes","Son de piedra y estan completamente recubiertas de moho"
".\n");
add_item("pieles","No sabes que tipo de ser las tenia antes.\n");
add_item("moho","Recubre todas las paredes, parece mentira que en un lugar "
"como este puedanpervivir.\n");
add_item(({"suelo","mierda"}),"Te daria nauseas tocarlo.\n");    
set_light(0);
add_exit(N ,NIVEL2+"c15","corridor");
add_exit(E ,NIVEL2+"c22","corridor");
add_exit(SE,NIVEL2+"c23","corridor");
add_exit(SO,NIVEL2+"c11","corridor");
add_exit(NO,NIVEL2+"c09","corridor");
add_clone(CLOACABICHO+"espantajo",random(2));

}
