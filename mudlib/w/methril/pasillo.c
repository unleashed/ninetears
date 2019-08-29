/* Methril Ethril 2002*/
#define CREATOR "Methril"

inherit "/std/artico.c";
void setup() {
	set_short("%^BOLD%^Oscuro%^RESET%^ lugar de la casa de %^BOLD%^%^BLACK%^Meth%^RESET%^%^BOLD%^%^WHITE%^ril%^RESET%^");
	set_long(query_short()+"
   La oscuridad envuelve este pasillo. Podria habersete apagado el candelabro, y "+
		"por eso no logras ver nada.

");

}

void init() {
   	::init();
   	add_action("ver",({"mirar","look"}));
}


int ver( ) {
	tell_room("No se como saber si el player lleva el candelabro")
	if(member_array("/w/methril/candelabro.c",all_inventory(TP))!=-1) {
		TO->set_short("%^BOLD%^Oscuro%^RESET%^ pasillo de la casa de %^BOLD%^%^GREY%^"+capitalize(CREATOR)+"%^RESET%^");
		TO->set_long(query_short()+
			"
   Unas paredes exccavadas en la roca parecen conducir a un lugar hacia abajo. Sientes miedo y a la vez curiosidad"+
			"pero aun asi no logras calmar tu curiosidad y decides seguir hacia abajo.

");
		TP->add_item(({"pared","paredes"}),"Las estrechas paredes que te rodean estan compuestas de la misma negra y fria roca que los muros del lugar donde encontraste el candelabro.
");
		add_exit("abajo","/w/methril/pasillo2.c","door");
		
		renew_exits();
		return 1;
   	}
   	notify_fail("Todo parece limpio menos el escritorio.
");
   	return 0;
}
