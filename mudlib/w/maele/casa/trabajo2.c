inherit "/std/room.c";

void setup() {
	set_short("%^GREEN%^Interior del arbol%^RESET%^");
	set_long(query_short()+"\n   El interior del arbol es espectacular, una enorme escalera de caracol totalmente hecha de madera atraviesa el arbol por su centro, Aqui la escalera termina y ves como la estancia esta parcialmente cubierta de suelo, a un lado colgando de una cuerda ves una canasta de mimbre.\n\n");
	add_item("canasta","Una canasta de mimbre, delicadamente trabajada en la que piensas que cabe una persona.");
	add_item("escalera","Una escalera de caracol, que al fijarte puedes observar como la savia circula por la barandilla.");
 	add_exit("abajo","/w/maele/casa/trabajo1.c","door");
   	}
void init() {
	::init();
	add_action("canasta","subir");
	}
int canasta(string str) {
	if(str=="a la canasta") {
		tell_object(TP,"subes a la canasta y esta comienza a ascender.\n");
		tell_room(TO,TP->query_cap_name()+" sube a la canasta y esta comienza a subir.\n",TP);
		this_player()->move("/w/maele/casa/mirador.c");
		return 1;
		}
	notify_fail("comorl???");
	return 0;
	}