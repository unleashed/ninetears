inherit "/obj/comida";

void setup() {
	set_name("vino tinto de rongrond");
	set_short("%^BOLD%^RED%^Vino tinto de Rongrond%^RESET%^");
	set_long(query_short()+"\nUna Botella del mejor vino tinto de Faeleen, es un gran vino cultivado en los vinyedos del sur de Rongrond.\n");
	add_alias("vino");
	add_aloas("botella");
	set_main_plural("Botellas de vino");
	add_plural("vinos");
	add_plural("botellas");
	set_value(500);
	set_weight(10);
	set_tipo("alcohol");
	set_curacion(45);
	}
void mostrar_mensajes(object me) {
	tell_object(me,"Te bebes una botella de este vino tinto, probablemente es es mejor vino del mundo.\n");
	tell_room(ENV(me),me->query_cap_name()+" se bebe una botella de vino de rongrond y los morros se le quedan manchados de vino.\n",me);
	}