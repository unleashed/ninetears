#define CREATOR "maele"
inherit "/std/bosque.c";

void setup() {
	set_short("%^BOLD%^GREEN%^Arbol Milenario%^RESET%^");
	set_long(query_short()+"\n   Al contemplar este arbol, te das cuenta de los anyos que habra visto pasar, de lo profundas que han de ser sus raices. El tronco tan grueso que quiza ni 50 hombres podrian rodearlo te una impresion de poder y majestuosidad que no podrias haber imaginado nunca.Las ramas cubren el sol casi por completo.\n\n");
 	add_item("ramas","Las ramas gruesas como arboles adultos salen por todo el tronco creando un curioso techo vegetal.\n");
   	add_item("tronco","El tronco muy grueso esta lleno de muescas y extranyos simbolos en su base, quiza hechos con los anyos por seres inteligentes.\n");
   	add_item("simbolos","Uno de los simbolos llama tu atencion, parece ser el mas antiguo y es una gran M que sobresale en relieve de la madera.\n");
 	add_smell("aire","El aire es pesado y extranyamente seco aqui.\n");
   	add_feel("tronco","Sientes el rugoso tacto de la madera antigua.\n");
   	add_sound("aire","Escuchas el trinar de los pajaros y diversos ruidos del bosque.\n");
  	add_exit("comun","/w/common","door");
   	"/w/common.c"->add_exit( "maele","/w/maele/workroom.c","door");
	}
void init() {
	::init();
	add_action("activar","presionar");
	add_action("desactivar","ulular");
	}
int activar(string str) {
	if(str=="M de madera") {
		tell_object(TP,"Presionas la M de madera y escuchas un ruido caracteristico en el tronco del arbol.\n");
		tell_room(TO,TP->query_cap_name()+" toca algo en el arbol y este comienza a crujir.\n",TP);
		add_exit("grieta","/w/maele/casa/trabajo1.c","door");
		"/w/maele/casa/trabajo1.c"->add_exit("fuera","/w/maele/workroom.c","door");
		renew_exits();
		return 1;
		}
	notify_fail("comorl???");
	return 0;
	}
int desactivar(string str) {
	if (str=="como un buho") {
		tell_object(TP,"Al ulular como un buho el arbol reacciona y cierra la grieta.\n");
		tell_room(TO,TP->query_cap_name()+" ulula como los buhos y la grieta se cierra.\n",TP);
		remove_exit("grieta");
		"/w/maele/casa/trabajo1.c"->remove_exit("fuera");
		renew_exits();
		return 1;
		}
	notify_fail("comorlll??");
	return 0;
	}
		