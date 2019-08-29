/*  Text alterations and additions by Grimbrand 2-2-96                    */

#include "path.h"
inherit "/std/underground";

object *npcs;

/*
void reset() {
int i;
 for(i=0;i<sizeof(npcs);i++) {
  if(!npcs[i]) {
  npcs[i]=clone_object(DNPC+"dmaster02.c");
  npcs[i]->move(this_object());
  }
 }
}
*/

void setup() {
  add_property("no_undead",1); set_light(10);
  npcs = allocate(1);
set_short("Reinado Duergar:  Oficina de exploracion de superficie.");
set_long("\n   Reinado Duergar: Oficina de exploracion de superficie.\n\n"
	 "     Has entrado a la oficina del Maestro de exploraciones "
	 "de superficie. Aqui es donde deberas aprender sobre las "
	 "criaturas que pululan los reinos de superficie. El maestro "
	 "obviamente ha viajado alli muchas veces,juzgas,al ver los "
	 "numerosos objetos que solo pueden ser de las razas que "
	 "habitan el mundo solar. El escritorio a una parte del "
	 "cuarto esta hecho completamente de una madera oscura "
	 "que nunca habias visto.  Sobre el escritorio hay algunas "
	 "fruslerias.  A lo largo de las paredes cuelgan cabezas "
	 "de las diabolicas criaturas que el maestro ha encontrado "
	 "en sus viajes,y cubriendo el suelo estan las pieles tambien "
	 "de las bestias salvajes de superficie.\n");

add_item("escritorio",
	 "   El escrtorio es de una esplendida y brillante madera "
	 "oscura.  Se dice que tal madera proviene solo de los "
	 "bosques elfos del mundo exterior, y los elfos no comparten "
	 "de buena gana sus amados arboles.\n\n");

add_item("fruslerias",
	 "   Sobre el escritorio ves una pieza de cristal tallado "
	 "que usa como pisapapeles.\n\n");

add_item("cabezas",
	 "   De la pared cuelgan cabezas disecadas que el maestro  "
	 "colecciona.  Una parece de una gran serpiente gigante, "
	 "otra es la cabeza peluda de un enorme oso blanco.\n\n");

add_item("suelo",
	 "  El suelo esta totalmente cubierto con pieles de animales. "
	 "algunas extremadamente suaves,otras con hermosos patrones "
	 "multicolores.\n\n");

add_exit("noroeste",NEWBIE+"dlev3_01","door");
add_exit("sudeste",NEWBIE+"main03","door");
modify_exit("noroeste",({"function","bouncer"}));
add_clone(DNPC+"dmaster02.c",1);
}
/*
void dest_me() {
int i;
for(i=0;i<sizeof(npcs);i++)
  if(npcs[i]) npcs[i]->dest_me();

 ::dest_me();
}
*/
 
int bouncer() {
int lv,xp;
object me = this_player();
lv = (int)me->query_level();
xp = (int)me->query_xp();
if(lv == 2 && xp < 5500) {
write("   La puerta se abre de par en par dejandote pasar sin problema "
	 "alguno.\n\n");

tell_room(environment(me), me->query_cap_name()+" traspasa la puerta "
	 "al noroeste abierta de par en par,cerrandose suavemente "
	 "tras su paso "+me->query_objective()+".\n\n",
	 ({this_player()}));
	 return 1;
}
notify_fail("Te quedas atontado por unos momentos, tras "
	 "darte de morros contra la puerta cerrada.\n");

tell_room(environment(me), me->query_cap_name()+" se queda "
	 "atontado tras darse de morros contra la puerta cerrada.\n",
	 ({this_player()}));
	 return 0;
}
