inherit "/std/room.c";

void setup() {
	set_short("%^BOLD%^ORANGE%^Mirador%^RESET%^");
	set_long(query_short()+"\n   La vista desde aqui es espectacular, puedes ver todo el bosque antiguo a tus pies, y la base del arbol queda pequenya, un tejado de ramas y hojas, hace que las inclemencias del tiempo no te afecten aqui.\n\n");
	add_item("canasta","Una canasta de mimbre, delicadamente trabajada en la que piensas que cabe una persona.");
   	}
void init() {
	::init();
	add_action("canasta","subir");
	}
int canasta(string str) {
	if(str=="a la canasta") {
		tell_object(TP,"Subes a la canasta y esta comienza a descender.\n");
		tell_room(TO,TP->query_cap_name()+" sube a la canasta y esta comienza a bajar.\n",TP);
		this_player()->move("/w/maele/casa/trabajo2.c");
		return 1;
		}
	notify_fail("comorl???");
	return 0;
}
void event_enter(object ob) {
	if(ob->query_name()=="maele") {
		tell_object(TP,"Oyes un aletear entre las ramas y un aguila gigante aparece junto a ti.\n");
		tell_room(TO,"Se oye un aletear entre las ramas y un aguila se acerca al mirador.\n",TP);
		clone_object("/w/maele/casa/npc/aguila.c")->move("/w/maele/casa/mirador.c");
		return 1;
	}
	return 0;
}