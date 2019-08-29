inherit "/std/tienda";
#include "../../path.h"
void setup() 
	{
	set_short("%^BOLD%^BLUE%^Herreria de Ormer%^RESET%^o%^BOLD%^BLUE%^d%^RESET%^.");
	set_long(query_short()+"\nEstamos en la herreria de Ormerod, vemos una "
	"piedra enorme al lado de un horno, un mostrador, y unas lejas con objetos "
	"varios.\n");
	set_dependiente("/w/kryger/kozluk.c");
	// La funcion prohibir_venta() hace que en la tienda no se puedan vender objetos,
	//solo comprar. La usare en la herreria
	/////seria ---> prohibir_venta();
	// Como he implemtado el tipo herreria y quiero hacer una herreria pues le pongo
	//el tipo herreria
	set_tipo("herreria");
	add_suministro("/baseobs/armours/helmet",2);
	add_suministro("/baseobs/weapons/long_sword",random(5));
	add_suministro("/baseobs/shields/corporal",roll(1,3));
	// Esta vez probaremos los prohibidos
	//////add_prohibido("raza","enano");
	//////add_prohibido("alineamiento","legal bueno");
	// Ahora quiero una placa
	add_cartel();
	add_exit ("fuera",ROOMORM"cruce_ormerod.c","door");
	}

// Pues sabiendo hacer la tienda no es nada complicado hacer la herreria, digo yo
