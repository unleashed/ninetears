// Errante ene 1998 "Descripciones por Virus '98" Testeado y modificado para 
// que funcione por Spp ENE'98 Quitado de describe por Aokromes SEP'99
#include "../path.h"
inherit "/std/underground.c"; // Outside unas Cloacas???

void event_enter(object ob, string mensaje, object donde)
    {
      if(interactive(ob) && !(int)ob->query_timed_property("axfixia"))
         ob->add_timed_property("axfixia");
    }

void setup()
{

set_short("Entrada al segundo nivel de las cloacas");
set_long("Esta es la entrada al segundo nivel de las cloacas, ves bien "
         "debido a las antorcha que hay en las paredes.\n");
add_item(({"antorcha","antorchas"}),"Gracias a estas es ilumina toda la "
          "habitacion.\n");
set_light(10);
add_sign ("Peligro zona de cloacas altamente peligrosas.\n");
add_exit(AR,CLOACAS+"c15","stair");
switch(random(3))
{
case(0): add_exit(AB,NIVEL2+"c14","stair");
case(1): add_exit(AB,NIVEL2+"c29","stair");
case(2): add_exit(AB,NIVEL2+"c05","stair");
}
}

