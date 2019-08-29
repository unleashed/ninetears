#define YO "firehelp"

inherit "/std/room.c";

void setup () {

set_short("%^BOLD%^%^BLACK%^Habitacion %^RESET%^de "+capitalize(YO));

set_long("Es una gran habitacion, al entrar sientes inmediatamente una relajacion espiritual, al fondo puedes oir una radio que suena muy agradable, en el medio una gran cama la cual te transporta inmediatamente al mundo de los sue�os, en una pared puedes ver un cuadro.\n\n");

add_item("cama","Es una moderna y comoda cama...\n");

add_item("cuadro","Ves un lindo paisaje.\n");

add_item("radio","Una ro�osa y antigua radio.\n");

add_feel("cama","Es muy comoda.\n");

add_exit("norte","/w/firehelp/pasillo","door");

}

void init () {
	
	::init();
	
	add_action("move_desk","mover");
}

int move_desk(string str) {
	if(str == "cuadro") {
		tell_object(TP,"Mueves el cuadro y ves que detras tuyo se abre una puerta con unas escaleras hacia abajo.\n");
		tell_room(TO,this_player()->query_cap_name()+ " mueve el cuadro y ves como se abre un puerta con escaleras.\n",TP);
		
		add_exit("escaleras","/w/firehelp/sotano.c","door");
		
		renew_exits();
		return 1;
	}
	
	return notify_fail("Mover que?\n");
	}
	
 