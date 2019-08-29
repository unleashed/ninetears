inherit "/std/tienda";
#include "../path.h"
void setup() 
	{
	set_short("%^BOLD%^BLUE%^Herreria de la Discordia%^RESET%^");
	set_long(query_short()+"\n\nEstamos en la herreria del campo de la Discordia, vemos una "
	"piedra enorme al lado de un horno, un mostrador, y unas lejas con objetos varios.\n");
	add_exit("fuera",ROOMRING"campo_discordia_6.c");
	set_dependiente("/room/plaza/rasputin_discordia.c");
	// La funcion prohibir_venta() hace que en la tienda no se puedan vender objetos,
	//solo comprar. La usare en la herreria
	/////seria ---> prohibir_venta();
	// Como he implemtado el tipo herreria y quiero hacer una herreria pues le pongo
	//el tipo herreria
	set_tipo("herreria");
	add_suministro("/baseobs/armas/espada_bastarda",random(5));
	add_suministro("/baseobs/armas/espada_larga",random(5));
	add_suministro("/baseobs/armas/lanza",random(5));
	add_suministro("/baseobs/armas/hacha_a_dos_manos",random(5));
	add_suministro("/baseobs/armas/maza_a_dos_manos",random(5));
	add_suministro("/baseobs/armaduras/armadura_completa",random(5));
	add_suministro("/baseobs/armaduras/yelmo_grande",random(5));
	add_suministro("/baseobs/armaduras/yelmo",random(5));
	add_suministro("/baseobs/armaduras/guanteletes",random(5));
	add_suministro("/baseobs/escudos/corporal",random(5));
	add_suministro("/baseobs/escudos/escudo_medio",random(5));
	// Esta vez probaremos los prohibidos
	//////add_prohibido("raza","enano");
	//////add_prohibido("alineamiento","legal bueno");
	// Ahora quiero una placa
	add_cartel();
	}

// Pues sabiendo hacer la tienda no es nada complicado hacer la herreria, digo yo
