//Kryger 2002//
inherit "/std/tienda";
#include "../../path.h"
void setup() 
	{
	set_short("%^BOLD%^BLUE%^Herreria de Ormerod%^RESET%^.");
	set_long(query_short()+"\nEstamos en la herreria de Ormerod, vemos una "
	"piedra enorme al lado de un horno, un mostrador, y unas lejas con objetos "
	"varios.\n");
	add_exit("fuera",ROOMORMP"cruce_ormerod.c");
	set_dependiente("/d/faeleen/npc/krysh_ormerod.c");
	// La funcion prohibir_venta() hace que en la tienda no se puedan vender objetos,
	//solo comprar. La usare en la herreria
	/////seria ---> prohibir_venta();
	// Como he implemtado el tipo herreria y quiero hacer una herreria pues le pongo
	//el tipo herreria
	set_tipo("herreria");
	add_suministro("/baseobs/armaduras/yelmo.c",2);
	add_suministro("/baseobs/armaduras/anillo.c",random(5));
	add_suministro("/baseobs/armaduras/amuleto.c",random(5));
	add_suministro("/baseobs/armaduras/armadura_de_cuero.c",3);
	add_suministro("/baseobs/armaduras/brazaletes.c",2);
	add_suministro("/baseobs/armas/espada_larga.c",random(5));
	add_suministro("/baseobs/armas/latigo.c",random(5));
	add_suministro("/baseobs/armas/baston.c",2);
	add_suministro("/baseobs/escudos/corporal.c",roll(1,3));
	// Esta vez probaremos los prohibidos
	//////add_prohibido("raza","enano");
	//////add_prohibido("alineamiento","legal bueno");
	// Ahora quiero una placa
	add_cartel();
	}

// Pues sabiendo hacer la tienda no es nada complicado hacer la herreria, digo yo
