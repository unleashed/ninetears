// Aokromes Noviembre 1999

#include "../path.h"
inherit LABERINTO2+"cultivos";

void setup() {

   set_light(50);
   set_short("Cultivos de "PN);
   set_long("Estas en una senda entre los amplios cultivos del poblado de "
   +PN+" de vez en cuando ves casetas en las cuales los agricultores parecen "
   "guardar sus aperos o bien las semillas o las mercancias para llevarlas a "
   "la ciudad y que no se pierdan por el mal tiempo.\n");
  add_item("caseta","una caseta para guardar los aperos de labranza.\n");
crea_bichos();
add_exit("east",LABERINTO2+"senda_84.c","plain");
add_exit("southwest",LABERINTO2+"senda_91.c","plain");
}
