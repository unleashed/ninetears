// FUAAA, revisar pq no rula el static y que pasa con el cavar pa que
// tiren bien las direcciones.
inherit "/std/room.c";

static int encontrado = 0;

void setup()

{
    set_short("%^BOLD%^%^BLUE%^Hueco%^RESET%^");
     set_long("%^BOLD%^%^BLUE%^Hueco en el Camino%^RESET%^\n\n"
      "Te encuentras en un pequenyo hueco natural, tal vez fue en otro "
	"tiempo la guarida de algun animal del bosque.\n\n"
	"Parece bastante tranquilo, aunque no conviene bajar la guardia"
	".\n\n");

    set_light(40);

//add_exit("arriba","/room/camino_avalon/camino06","plain"); stairs?
}

void init() {
	//encontrado = 0;
	add_action("do_buscar", "buscar");
}

// mirar a ver si se puede hacer como objeto hidden y ver como para
// que no aparezca luego...
int do_buscar(string que)
{
	object mi_objeto;
	// argh, hack de mierda!
	TP->do_cmd("search");
	if (!encontrado) {
	mi_objeto = clone_object("/room/camino_avalon/objs/amuleto_elfico");
	tell_object(TP, "Encuentras lo que parece ser un amuleto entre "+
			"las hojas del suelo.\n");
	tell_room(ENV(TP), TP->QCN+" encuentra algo entre las hojas del suelo.\n", TP);
	mi_objeto->move(TO);
	encontrado = 1;
	}
}
