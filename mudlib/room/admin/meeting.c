#include "path.h"
inherit "/std/room";

#define LOGGER "/obj/handlers/meeting_log"
object floor;
string chair;
int last_say;
int log_souls;

void setup() {
  set_short("Sala de Juntas");
  set_long(
"Heaven:  Sala de Juntas.\n\n"
"Este sitio es la definici�n de la comodidad. A lo largo de las paredes roble-artesonadas "
"en cada lado est�n los estantes del libro que estiran toda la manera al alto techo. Una esquina "
"tiene una tabla adornada con las varias jarras del licor. El centro del cuarto se llena de todos "
"los tipos de sillas grandes, suaves. Cada uno tiene un taburete del pie y una tabla peque�a al lado "
"de �l. Cowering en otra esquina usted ve a escribano joven r�pidamente el tomar de notas.\n");
  add_exit("sur","/w/common","door");
  set_light(45);

  add_item("pared","�stas son paredes artesonadas roble, simuladas. �Qu� m�s usted hicieron que dijera sobre ellas? \n");
  add_item("libro","Los estantes todos se llenan de antiguo cuero-limitan vol�menes. Su colecci�n debe haber tomado una absolutamente cierta hora. \n");
  add_item("tabla","todas las tablas se hace de maderas duras y es adornado crafted.\n"); 
  add_item("ceiling", "este sitio debe ser dos historias altas. Usted tiene apuro que ve cualquier detalle del ceiling.\n"); 
  add_item("liquor decanters","Made of a fine crystal, these decanters "
           "hold any sort of alcohol you might want.\n");
  add_item("chair","The chair looks extremely comfortable.\n");
  add_item("foot stool","The stool is just what you need to fully relax "
           "during a meeting.\n");
  add_item("escriba","Siendo un hombre muy joven, este escribano se siente empequenyecido por el caracter "
	   "de la reunion. Cuidadosamente �l toma nota de lo hablado en la reuni�n.\n");
}

void reset() {
  if (floor)
    return ;
  floor = clone_object("/std/object");
  floor->set_name("piso");
  floor->set_short("El piso");
  floor->set_long("�ste es el piso de la reuni�n. Le da la derecha de hablar durante la reuni�n. D� por favor esto a la persona siguiente para hablar despu�s de que usted haya acabado.\n");
  floor->move(this_object());
}

void init() {
  string str;

  ::init();
  add_action("log_mode","logmode");
/* So I just banged my gavel.
 * You did what?
 * I banged my gavel and did the "order in the court thing"
 */
  if
("/secure/master"->high_programmer((str=(string)this_player()->query_name()))
      || str == chair) {
    add_action("appoint", "appoint");
    add_action("bang", "bang");
    add_action("recover", "recover"); /* recovers the floor in case of
                                       * loss */
  }
}

int appoint(string str) {
  object ob;

  if (chair && (string)this_player()->query_name() != chair) {
    notify_fail("La silla se ha designado ya. \n");
    return 0;
  }
  if (!(ob = find_player(str))) {
    notify_fail("Lo siento, no puedo encontrar a "+str+" para que sea la silla.\n");
    return 0;
  }
  chair = str;
  say(this_player()->query_cap_name()+" designa a "+str+" como "+
        "silla del encuentro.\n", ob);
  write("Vale, "+str+" es ahora la silla del encuentro.\n");
  tell_object(ob, this_player()->query_cap_name()+
        " te ha senyalado como silla del encuentro.\n");
  if (environment(ob) != this_object())
    ob->move(this_object());
  return 1;
}

int bang(string str) {
  if ((string)this_player()->query_name() != chair) {
    notify_fail("Solamente la silla puede golpear el mazo.\n");
    return 0;
  }
  tell_room(this_object(),
            this_player()->query_cap_name()+" golpea el mazo con fuerza.  %^BOLD%^MAGENTA%^STOP!!! "+
            "STOP!!!!%^RESET%^\n");
  return 1;
}

int recover() {
  if (!floor)
    reset();
  floor->move(this_player());
  write("Piso recuperado.\n");
  say(this_player()->query_cap_name()+" ha recuperado el piso.\n");
  return 1;
}

int log_mode(string str) {
  log_souls = !log_souls;
  
  if(log_souls)
    tell_object(this_player(),"Souls seran logueados.\n");
  else
    tell_object(this_player(),"Souls NO seran logueados.\n");

  return 1;
}

/* this will divide up separate conversation. */
void check_expired() {
  if( (time() - last_say) > (600) )
    LOGGER->log_it("* * * * *\n");
    
  last_say = time();
}

void event_person_say(object ob, string start, string rest,string lan) {
  check_expired();
  LOGGER->log_it(start+rest+"\n");
  ::event_person_say(ob,start,rest,lan);
}

void event_say(object ob, string rest) {
  check_expired();
  LOGGER->log_it(rest);
}

void event_soul(object ob, string rest) {
  if(log_souls) {
    check_expired();
    LOGGER->log_it(rest);
  }
}

void dest_me() {
  if (floor)
    floor->dest_me();
  ::dest_me();
}
