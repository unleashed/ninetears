inherit "/std/outside.c";

     string long = "%^CYAN%^Camino en construccion a Avalon%^RESET%^\n\n"
      "Este camino esta siendo construido senyalizado y debidamente "
	"pavimentado por los elfos. Como bien puedes observar, los "
	"arboles abundan mucho por aqui, asi que ir abriendo camino "
	"llevara cierto tiempo a esta noble raza. El objetivo es "
	"obtener un camino seguro que comunique esta zona con la "
	"ciudad de Avalon.\n\n";

void do_desc(int do_long)
{
    set_short("%^CYAN%^Camino en construccion a Avalon%^RESET%^");
	/* dark_mess para oscuridad */
	set_dark_mess("Tan solo intuyes que te encuentras en el camino "
		"a Avalon.\n");
	/* dark_long para cuando es de noche (solo en outsides) */
	set_dark_long("%^CYAN%^Camino en construccion a Avalon%^RESET%^\n\n"
		"El camino tiene un ambiente lobrego a estas horas "
		"de la noche. Al no estar acabado, no es ruta de paso "
		"habitual, por lo que no tiene el colorido ni la luz de "
		"otras grandes rutas. Poco puedes ver ahora.\n");
	if (do_long)
		set_long(long);

add_item("camino","El camino esta bien trazado, evitando los escollos "
	"naturales en la medida de lo posible, si bien aun queda mucho "
	"por hacer para que se parezca en algo a un camino Real.\n");

add_item(({"arbol", "arboles", "bosque"}), "Un espeso bosque donde a "
	"buen seguro habitan los elfos es el mayor impedimento para "
	"que el camino se termine rapidamente.\n");
	set_zone("camino_avalon");
}
