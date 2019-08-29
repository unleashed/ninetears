inherit "/std/room.c";

void setup() {
	set_short("%^GREEN%^Interior del arbol%^RESET%^");
	set_long(query_short()+"\n   El interior del arbol es espectacular, una enorme escalera de caracol totalmente hecha de madera atraviesa el arbol por su centro, yendo de abajo a arriba, hasta saber que lugares llegara esa escalera.\n\n");
	add_item("rama","Una rama seca pende del interior del tronco.");
	add_item("escalera","Una escalera de caracol, que al fijarte puedes observar como la savia circula por la barandilla.");
 	add_exit("arriba","/w/maele/casa/trabajo2.c","door");
 	add_exit("abajo","/w/maele/casa/sub1.c","door");
   	}
void init() {
	::init();
	add_action("cerrar","girar");
	add_action("abrir","torcer");
	}
int cerrar(string str) {
	if(str=="rama seca") {
		tell_object(TP,"Giras la rama hacia la derecha y la grieta comienza a cerrarse.\n");
		tell_room(TO,TP->query_cap_name()+" gira la rama y este comienza a crujir.\n",TP);
		"/w/maele/workroom.c"->remove_exit("grieta");
		remove_exit("fuera");
		renew_exits();
		return 1;
		}
	notify_fail("comorl???");
	return 0;
}
int abrir(string str) {
	if(str=="rama seca") {
		tell_object(TP,"Giras la rama a la izquierda y la luz se empieza a colar por una grieta que se forma en una de las paredes.\n");
		tell_room(TO,TP->query_cap_name()+" gira la rama a la izquierda y se comienza a colar la luz a traves de una grieta de la pared.\n",TP);
		"/w/maele/workroom.c"->add_exit("grieta","/w/maele/casa/trabajo1.c","door");
		add_exit("fuera","/w/maele/workroom.c","door");
		renew_exits();
		return 1;
	}
	notify_fail("comorl???");
	return 0;
}