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

set_long("Con el rato que llevas circulando por estas cloacas, puedes sentir "
"como los pies te pesan una barbaridad por culpa del barro que se pega a las "
"suelas de tu calzado. Aqui el nivel del agua ha subido un poco, tal que te "
"llega al tobillo. El agua es pestilente y negra. Las paredes estan llenas de "
"insectos roiendo una piel de serpiente bastante grande. El aire del lugar "
"escasea. Notas como si no supieses donde estas.\n");


add_item("paredes","Son de piedra y estan completamente recubiertas de moho"
".\n");
add_item("pieles","No sabes que tipo de ser las tenia antes.\n");
add_item("moho","Recubre todas las paredes, parece mentira que en un lugar "
"como este puedanpervivir.\n");
add_item(({"suelo","mierda"}),"Te daria nauseas tocarlo.\n");    
set_light(0);

add_exit(N ,NIVEL2+"c33","corridor");
add_exit(E ,NIVEL2+"c04","corridor");
add_exit(SE,NIVEL2+"c05","corridor");
add_exit(S ,NIVEL2+"c35","corridor");
add_exit(O ,NIVEL2+"c28","corridor");
set_zone("nivel2");
add_clone(CLOACABICHO+"espantajo",random(2));
}
void Reset(string Num)
{
}

