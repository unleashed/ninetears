//Kryger 2002//
inherit "/obj/comida";

void setup() {
	set_name("Jamon");
	set_short("Jam�n");
	set_long(query_short()+"\n\n"+"Es una Jam�n grande, es una de las especialidades de la "
	"carniceria, se ve a simple vista que esta bi�n curado.\n");
	add_alias("jamon");
	add_alias("jamon");
	set_main_plural("jamones");
	add_plural("jamones");
	set_value(350);
	set_weight(10);
	set_curacion(10);
	call_out("corromper",1000);
	}
void mostrar_mensajes(object me) {
	tell_object(me,"Te comes un trozo de jam�n, parece estar bueno.\n");
	tell_room(ENV(me),me->query_cap_name()+" se come un trozo de jam�n.\n",me);
	}