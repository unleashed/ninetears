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

set_long("Un hedor fulminante que proviene del suelo hace que te "
"tapes la nariz, parece que hayan matado a alguien y lo "
"hayan dejado ahi tirado. Las paredes estan resbaladizas "
"por culpa del moho que las cubre. El suelo esta enfangado "
"y repleto de extranyos bichos que corretean a sus anchas "
"entre la mierda. Del techo cuelgan pieles que no parecen "
"humanas, que ademas estan frescas y chorrean sangre. Se "
 "respira bastante mal aqui, Y notas como que estas perdido.\n");


add_item("paredes","Son de piedra y estan completamente recubiertas de moho"
".\n");
add_item("pieles","No sabes que tipo de ser las tenia antes.\n");
add_item("moho","Recubre todas las paredes, parece mentira que en un lugar "
"como este puedanpervivir.\n");
add_item(({"suelo","mierda"}),"Te daria nauseas tocarlo.\n");    
set_light(0);

add_exit(E ,NIVEL2+"c35","corridor");
add_exit(SE,NIVEL2+"c36","corridor");
add_exit(S ,NIVEL2+"c30","corridor");
add_exit(NO,NIVEL2+"c22","corridor");


}
