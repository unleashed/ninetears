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

set_long("Es impresionante la mierda que puede llegar a acumular una "
"cloaca de este tipo. Te encuentras ante una concentracion de moscas "
"revoloteando alrededor de algo parecido a una piedra. "
"En las paredes hay mas moho de lo normal y hay mucha humedad, es "
"evidente que estas a bastante profundidad del nivel del suelo, "
"ademas te debes encontrar en el paso de un rio subterraneo, ya "
"que del techo caen pequenyos chorrillos de agua fria. Huele y se "
"respira mal. Te notas como desconcertado.\n");


add_item("paredes","Son de piedra y estan completamente recubiertas de moho"
".\n");
add_item("pieles","No sabes que tipo de ser las tenia antes.\n");
add_item("moho","Recubre todas las paredes, parece mentira que en un lugar "
"como este puedanpervivir.\n");
add_item(({"suelo","mierda"}),"Te daria nauseas tocarlo.\n");    
set_light(0);

add_exit(NE,NIVEL2+"c26","corridor");
add_exit(SE,NIVEL2+"c28","corridor");
add_exit(S ,NIVEL2+"c22","corridor");
add_exit("abajo",NIVEL2+"c37","corridor");
add_exit(O ,NIVEL2+"c15","corridor");
add_exit(NO,NIVEL2+"c14","corridor");


add_clone(CLOACABICHO+"rata",random(8)+3);
}
