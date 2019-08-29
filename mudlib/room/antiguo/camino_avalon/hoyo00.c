inherit "/std/room.c";

int roca_apartada = 0;

void setup()
{
    set_short("%^BOLD%^%^BLUE%^Hueco en el Camino%^RESET%^");
     set_long("%^BOLD%^%^BLUE%^Hueco en el Camino%^RESET%^\n\n"
      "Te encuentras en un pequenyo hueco natural, tal vez fue en otro "
	"tiempo la guarida de algun animal del bosque.\n\n"
	"Parece bastante tranquilo, aunque no conviene bajar la guardia"
	". Jurarias haber escuchado algun ruido, pero no sabrias determinar"
	" nada sin escuchar con mayor atencion.\n\n");

    set_light(40);

	add_item("roca", "Una enorme roca situada en la zona noreste de la sala.");
	add_sound("ruido", "Jurarias escuchar un pequenyo ruido ahogado proviniente del noreste. Al acercarte a esa direccion ves una enorme roca.");
    add_exit("arriba","/room/camino_avalon/camino06","plain"); //stairs?
	add_exit("noreste", "/room/camino_avalon/hoyo01", "hidden");
  modify_exit("noreste", ({"function", "ver_salida", "message", "@Pierdes de vista a $N."}));
}

void init()
{
	::init();
	roca_apartada = 0;	// no se si es necesario
	add_action("apartar_roca", "apartar");
}

int apartar_roca(string str)
{
	if (str == "roca")
	{
		tell_object(TP, "Apartas ligeramente la roca con todas tus "+
		"fuerzas, suficiente para dejar un resquicio por el que "+
		"cabe tu cuerpo.\n");
		tell_room(ENV(TP), TP->QCN+" se aleja un poco y hace un pequenyo esfuerzo que no distingues a ver.\n", TP);
		roca_apartada = 1;
	}
	else
		tell_object(TP, "Quieres apartar algo?\n");
	return 1;
}

int ver_salida()
{
	if (roca_apartada) {
	  tell_object(TP, "Entras por el resquicio de la roca y esta se cierra tras de ti.\n");
	  roca_apartada = 0;
	  return 1;
	}
	notify_fail("Te das de bruces con una roca enorme.\n");
	if (TP->query_stoneskin_spell())
		TP->adjust_hp(-2*(random(3)+1));
	else
		TP->really_adjust_hp(-2*(random(3)+1));
	return 0;
}
