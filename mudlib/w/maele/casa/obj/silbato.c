inherit "/obj/armour";

// En realidad no es muy diferente de un arma
void setup() {
	// set_base_armour() para elegir el tipo de armadura, que podeis encontrar una lista de tipos en /table/armour_table.c
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
int do_tocar(string str) {
	if(!str) return notify_fail ("Debes indicar lo que tocas.\n");
	if(str=="silbato") {
		tell_object(TP,"Tocas el silbato sin ningun aparente resultado.\n");
		tell_room(ENV(TP),TP->query_cap_name()+" sopla con fuerza por el silbato, pero de este no sale ningun sonido, realmente, parece comico...\n",TP);
		clone_object("/w/maele/casa/npc/aguila.c")->move(ENV(TP));
		return 1;
		}
	return 0;
}

	
