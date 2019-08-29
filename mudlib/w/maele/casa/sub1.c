inherit "/std/room.c";

void setup() {
	set_short("%^GREEN%^Interior del arbol%^RESET%^");
	set_long(query_short()+"\n   El interior del arbol es espectacular, una enorme escalera de caracol totalmente hecha de madera atraviesa el arbol por su centro, aqui la escalera parece terminar en un suelo de madera.\n\n");
	add_item("escalera","Una escalera de caracol, que al fijarte puedes observar como la savia circula por la barandilla.");
 	add_exit("arriba","/w/maele/casa/trabajo1.c","door");
   	}
void init() {
	::init();
	add_action("cante","cantar");
	}
int cante(string str) {
	if(TP->query_name()!="maele") {
		tell_object(TP,"Cantas pero tu voz no sirve aqui.\n");
		return 0;
		}
	if(str=="la vida locaaaa") {
		tell_object(TP,"Cantas dulcemente esta vida loca, loca, loca! y oyes un ligero ruido en el suelo.\n");
		tell_room(TO,TP->query_cap_name()+" canta la vida loca, loca, loca y oyes un ligero sonido en el suelo.\n",TP);
		add_exit("abajo","/w/maele/casa/sub2.c","door");
		renew_exits();
		return 1;
		}
	notify_fail("comorl???");
	return 0;
	}