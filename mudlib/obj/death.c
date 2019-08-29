// Death, Version 2.0
// Complete recode of original "Cyric" version, now uses Grimbrand
// Now uses heart_beat instead of call_out's
// Radix - January 17, 1996

inherit "/std/object.c";

void person_died(string str);
void do_chat(string str);

object pl;
int cnt;

void person_died(string str) {
   	pl = find_living(str);
   	if(!pl) return;
   	pl->set_dead(1);
   	pl->add_timed_property("noregen",1,16);
   	set_heart_beat(1);
	}

void do_chat(string str) {
   	tell_object(pl,str+"\n");
   	return;
	}

void heart_beat() {
   	cnt++;

   	if(!pl) {
      		dest_me();
      		return;
   		}

   	switch(cnt) {
   		case(2) :
      		do_chat("Sientes cada fraccion de segundo de la caida hasta que tu cuerpo toca el suelo.");
      		break;
   		case(4) :
     		if(pl->query_creator()) do_chat("Has vivido este momento tantas veces que ya ni las recuerdas... Cada vez que ocurre ansias el descanso de la muerte, pero tu alma no es capaz de abandonar tu cuerpo...");
      		else do_chat("Imagenes de tu vida, actos buenos y malvados, algunas de ellas olvidadas hace un largo tiempo, invaden tu mente, y cierras los ojos tratando de apartarlas.");
      		break;
   		case(6) :
      		if(pl->query_creator()) {
         		do_chat("Mientras te levantas comprendes que esa es la maldicion de ser Inmortal, pero justo un momento despues te olvidas de ello como algo sin importancia. \"Aun queda mucho por hacer\", dices para tus adentros, mientras esbozas una cinica sonrisa.");
         		pl->remove_timed_property("noregen");
			pl->remove_ghost();
TO->dest_me();
         		break;
      			}
      		else do_chat("Deseas el abrazo del olvido, ignorar el profundo sufrimiento que tu alma te inflinge mientras se separa del cuerpo, como si te desgarrase las entranyas desde dentro.");
      		break;
   		case(8) :
     		do_chat("Pero el dolor se apaga y este no llega, asi que abres lo que deben ser los ojos de un espiritu...");
      		break;
   		case(10) :
      		do_chat("Te rodea un mundo macabro, es el mismo lugar donde has muerto, pero todo esta deslustrado... y gris. Te sorprende la ausencia de color del mundo que te rodea, pero en el fondo no te preocupa. Hay vida despues de la muerte, y tu vas a disfrutar de ella.");
      		break;
   		case(12) :
      		do_chat("Entonces te descubres atad"+(pl->query_gender()-1?"a":"o")+" a tu cuerpo, como atraido por una misteriosa fuerza que aun te mantiene entre los mortales, aunque ese no es tu sitio. Entiendes que esta es tan solo la primera etapa de un largo viaje... y algo en tu instinto te dice que el final del camino no es de lo mas agradable.");
      		pl->remove_timed_property("noregen");
      		call_out("dest_me",0);
      		break;
   		}
	}
