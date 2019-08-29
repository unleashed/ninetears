inherit "/obj/armour";
void setup() {
   	set_base_armour("collar");
   	set_name("silbato");
   	set_short("%^BOLD%^RED%^Silbato%^RESET%^");
   	add_alias("silbato");
   	add_plural("silbatos");
   	set_main_plural("silbatos");
   	set_long(query_short()+"\n Un silbato de color rojo.\n");
   	reset_drop();
	}
void init() {
	::init();
	add_action("do_tocar","tocar");
}
void llamada(object tipo) {
	tell_object(TP,"Tocas el silbato sin ningun aparente resultado.\n");
	tell_room(ENV(TP),TP->query_cap_name()+" sopla con fuerza por el silbato, pero de este no sale ningun sonido, realmente, parece comico...\n",TP);
	call_out("llamada2",4,tipo);
}
void llamada2(object tipo) {
	tell_object(TP,"Oyes un aleteo proveniente del cielo.\n");
	tell_room(ENV(TP),"De pronto se oye un fuerte batir de alas.\n",TP);
	clone_object("/w/maele/casa/npc/aguila.c")->move(ENV(TP));
}
int do_tocar(string str) {
	if(!str) return notify_fail ("Debes indicar lo que tocas.\n");
	if(TP->query_property("silbato_tocado")) {
		tell_object(TP,"No puedes tocar el silbato aun.\n");
		return 1;
	}
	else {
		if(str=="silbato") {
			
			this_player()->add_timed_property("silbato_tocado",1,8);
			llamada(this_player());
			return 1;
		}
	}
	return 0;
}



	
