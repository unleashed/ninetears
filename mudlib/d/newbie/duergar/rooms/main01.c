/*  Text alterations and additions by Grimbrand 2-3-96                */

#include "path.h"
inherit "/std/underground";

object *npcs;

void reset() {
int i;
 for(i=0;i<sizeof(npcs);i++) {
  if(!npcs[i]) {
  npcs[i]=clone_object(DNPC+"duggan");
  npcs[i]->move(this_object());
  }
 }
}

void setup() {
  add_property("no_undead",1); set_light(10);
  npcs = allocate(1);
set_short("Reinado duergar:     Oficina de Maestros del Gremio");
set_long("\n   Reinado Duergar:  Oficina de Maestros del gremio.\n\n"
	 "     Entras a la oficina de Maestros del gremio.Es aqui "
	 "donde todos los duergas vienen a entrenarse para ser capaces "
	 "de sobrevivir en los reinos.La habitacion esta poco decorada "
	 ",solo una silla y una mesa. Con todo,las paredes estan  "
	 "cubiertas con prodigos murales representando acontecimientos."
	 "Deben ser de valor incalculable,debido al intrincado trabajo " 
	 "que debio suponer hacerlos.El Maestro se sienta en su silla "
	 "pacientemente esperando que le prestes atencion. Seria sabio "
	 "  -escuchar-  lo que tiene que decirte. "
         "\n\n");

add_exit("norte",NEWBIE+"main02","door");
//add_exit("sur",BUILD+"dhall1","door");
//add_exit("sur","/d/avalon/rooms/ciudad/a0001.c","door");
add_exit("sur","/d/driade/entryroom.c","door");
modify_exit("sur",({"function","bounced"}));
modify_exit("norte",({"function","bouncer"}));
}

void dest_me() {
   int i;
   for(i=0;i<sizeof(npcs);i++)
   if(npcs[i]) npcs[i]->dest_me();
   ::dest_me();
}
 
int bouncer() {
int lv;
object me = this_player();
lv = (int)me->query_level();
if(lv <= 4) {
write("Empujas la puerta y se abre sin ruido.  Alguien "
	 "se tomo su tiempo en engrasar las bisagras.\n\n");
tell_room(environment(me), me->query_cap_name()+" empuja la puerta al norte "
	 "y esta se abre dejandole pasar.\n\n",
	 ({this_player()}));
   return 1;
}
notify_fail("Eres incapaz de abrir la puerta.\n\n");
tell_room(environment(me), me->query_cap_name()+" intenta abrir la puerta "
	"al norte pero falla.\n\n",({this_player()}));
return 0;
}

int bounced() {
int lv;
int xp;
object me = this_player();
lv = (int)me->query_level();
xp = (int)me->query_xp();
//if(lv>=5&&xp>30000) { me->adjust_xp(-xp+1000); }
if(lv >= 5){
write("Abres la puerta que conduce afuera de los reinos de la academia"
"\n\n");
tell_room(environment(me), me->query_cap_name() +" Abre la puerta al sur "
	"dejando la academia.\n\n",
	({this_player()}));
   return 1;
}
notify_fail("No te has ganado el derecho a abandonar la academia aun!"
	    "\n\n");
tell_room(environment(me), me->query_cap_name() +" se plantea dejar  "
	"la academia pero decide que no,ya que  "+
	 this_player()->query_pronoun()+" no ha terminado "+
	 this_player()->query_possessive()+" entrenamiento aun.\n\n",
	 ({ this_player() }));
   return 0;
}

