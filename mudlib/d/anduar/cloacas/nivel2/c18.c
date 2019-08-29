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

set_long("Te encuentras ante un monton de residuos apelotonados por culpa de "
"una roca que ha caido del techo. No hay agua y el suelo no esta tan fangoso "
"porque la piedra obstruye parte del paso del agua. Las paredes estan medio "
"derrumbadas a causa de el paso del tiempo. Del techo de la cloaca cuelgan "
"unas hierbas que dificultan el paso, pero entre las hierbas y la roca hay "
"un hueco por el que puedes pasar. Hay poca corriente de aire en la cloaca. "
"Estas perdido.\n");
add_item("roca","Es una simple roca, pero muy pesada, si se le callese a "
"alguien encima se lo cargaria.\n");


add_item("paredes","Son de piedra y estan completamente recubiertas de moho"
".\n");
add_item("pieles","No sabes que tipo de ser las tenia antes.\n");
add_item("moho","Recubre todas las paredes, parece mentira que en un lugar "
"como este puedanpervivir.\n");
add_item(({"suelo","mierda"}),"Te daria nauseas tocarlo.\n");    
set_light(0);

add_exit(N ,NIVEL2+"c17","corridor");
add_exit(E ,NIVEL2+"c24","corridor");
add_exit(S ,NIVEL2+"c13","corridor");
add_exit(O ,NIVEL2+"c12","corridor");

add_clone(CLOACABICHO+"rata",random(8)+3);
}
