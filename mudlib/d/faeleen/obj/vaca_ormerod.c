//Kryger 2002//
inherit "/obj/comida";

void setup() {
	set_name("Ternera");
	set_short("Filete de Ternera");
	set_long(query_short()+"\n\n"+"Es un filete de ternera bi�n cortado y algo grande.\n");
	add_alias("ternera");
	add_alias("filete");
	set_main_plural("filetes");
	add_plural("filetes");
	set_value(250);
	set_weight(10);
	set_curacion(10);
	call_out("corromper",1000);
	}
void mostrar_mensajes(object me) {
	tell_object(me,"Te comes un filete de ternera, parece estar bueno.\n");
	tell_room(ENV(me),me->query_cap_name()+" se come un filete de ternera.\n",me);
	}