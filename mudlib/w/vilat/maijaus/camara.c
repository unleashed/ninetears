//Vilat 20.07.2002
inherit "/std/room.c";

void setup() {
  set_short("Camara de Supresion: El Cargador");
  set_long("Te encuentras en una habitacion completamente vacia, todo cuanto te rodea es blanco, un blanco infinito que te hace sentirte pequenyo. Tus pies reposan sobre el blanco de la habitacion como siempre lo han hecho, exceptuando el hecho de que no hay suelo debajo de ti. Es como si estuvieses en un extranyo limbo.\n");
  set_light(110);

  add_item(({"pared","suelo","techo","paredes","blanco"}),"Un desierto de blancura te rodea.");
  add_sound("habitacion","No se escucha ningun ruido en la habitacion.");
  
  add_exit("fuera","/w/vilat/maijaus/lvl1","door");
}

void init() {
  ::init();
  add_action("cargador","cargar");
  }
  
int cargador(string str){
  object *todos=all_inventory(TO);
  if (TP->query_cap_name()!="Vilat") {
  	notify_fail("No tienes el conocimiento necesario para utilizar el Cargador.\n");
  	return 0;
  } else {
  	if (!str) {
  		notify_fail("Nada que cargar.\n");
  		return 0;
  		}
  	"/w/vilat/maijaus/lvl1"->modify_exit("dentro",({"dest","/w/vilat/maijaus/cargador/"+str+".c"}));
  	"/w/vilat/maijaus/lvl1"->renew_exits();
  	for (int i=0;i<sizeof(todos);i++){
  		todos[i]->move("/w/vilat/maijaus/cargador/"+str+".c");
  		tell_object(todos[i],"Vilat comienza a hablarte pero no eres capaz de entender sus palabras. Te quedas ensimismado observando como sus labios se abren y se cierran vocalizando unas palabras que no llegan a tus oidos. Cuando vuelves a tomar nocion de la realidad, te das cuenta de que ya no te encuentras en la Camara de Supresion.\n");
  		continue;
  	}
  	return(1);
	}
}