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

set_long("El hedor continua hasta hacerse insoportable, te preguntas que te "
"ha inducido a entrar en esta pestilente cloaca. De las paredes cuelgan unas "
"extranyas enredaderas rocas, y ademas gotean algo de color roco sangre. Por "
"las enredaderas corretean unos insectos alargados de color azul oscuro, son "
"extremadamente pequeos y hay miles de ellos, ademas no parecen peligrosos. "
"El suelo esta bastante resbaladido a causa de que no hay suficiente barro "
"para que se te encallen los pies. No puedes respirar muy bien. Estas perdido"
".\n");


add_item("paredes","Son de piedra y estan completamente recubiertas de moho"
".\n");
add_item("pieles","No sabes que tipo de ser las tenia antes.\n");
add_item("moho","Recubre todas las paredes, parece mentira que en un lugar "
"como este puedanpervivir.\n");
add_item(({"suelo","mierda"}),"Te daria nauseas tocarlo.\n");    
set_light(0);

add_exit(N ,NIVEL2+"c23","corridor");
add_exit(E ,NIVEL2+"c30","corridor");
add_exit(S ,NIVEL2+"c19","corridor");
add_exit(O ,NIVEL2+"c18","corridor");
add_exit(N ,NIVEL2+"c30","corridor");
add_exit(E ,NIVEL2+"c31","corridor");
add_exit(S ,NIVEL2+"c26","corridor");
add_exit(O ,NIVEL2+"c19","corridor");
add_clone(CLOACABICHO+"espantajo",random(2));

}
