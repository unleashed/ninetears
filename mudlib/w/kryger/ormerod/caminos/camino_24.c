inherit "/std/room.c";

void setup ()
{
	set_short("%^BOLD%^YELLOW%^Camino%^RESET%^.");
	set_long("%^BOLD%^YELLOW%^Camino%^RESET%^.\n\n"
	"Es un camino sin calzar, de gravilla, tiene unos diez metrtos de ancho"
	"y esta acotado por piedras en los bordes.Esta muy marcado y desgastado"
	"por el paso de vacas y carros,tambien a los lados vemos unos pastos"
	"verdes.\n");
	set_light(100);
	add_exit("este","/w/kryger/ormerod/caminos/camino_26.c","door");
	add_exit("noroeste","/w/kryger/ormerod/caminos/camino_21.c","door");
	add_exit("noreste","/w/kryger/ormerod/pastos/pasto_150.c","door");
}