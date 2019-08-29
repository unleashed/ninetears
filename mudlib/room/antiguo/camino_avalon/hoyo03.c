inherit "/std/room.c";

object ogro;

void setup()
{
    set_short("%^BOLD%^%^BLUE%^Caverna en el Camino: Morada del Ogro%^RESET%^");
     set_long("%^BOLD%^%^BLUE%^Caverna en el Camino: Morada del Ogro%^RESET%^\n\n"+
      "Todo cobra ahora su sentido. Un asqueroso ogro ha morado esta "
	"caverna durante anyos. La sala esta banyada de cuerpos variando "
	"desde pequenyos animales a esqueletos del tamanyo de las gentes grandes.\n\n");

    set_light(30);
	add_item(({"cuerpos", "esqueletos", "esqueleto"}), "Cientos o quizas miles de pequenyos esqueletos y huesos cruelmente rotos pueblan la sala.");

	add_exit("noroeste","/room/camino_avalon/hoyo02","door");
	modify_exit("noroeste", ({"function", "go_salir"}));
}

// esto hay q hacerlo en reset, si se hace en init casca!
void reset()
{
	if (!ogro) {
		ogro = clone_object("/room/camino_avalon/npcs/ogro");
		ogro->move(TO);
	}
	::reset();
}

int go_salir()
{
	if (!ogro || TP->query_dead())
		return 1;
	TP->attack_by(ogro);	// por si entramos en el juego con el ogro ahi
	if (random(3)) {
	if (!TP->adjust_hp(-20-random(20), ogro)) {
		tell_object(TP, "El ogro te pega un bestial zarpazo para apartarte de la salida pero no lo consigue.\n");
		return 1;
	}
	notify_fail("El ogro te pega un bestial zarpazo apartandote de la salida.\n");
	return 0;
	}
	return 1;
}
