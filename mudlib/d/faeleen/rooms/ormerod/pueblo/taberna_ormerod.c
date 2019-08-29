//Kryger 2002//
inherit "/std/hostal";
#include "../../../path.h"


void setup() {
  	set_short("%^BOLD%^BLUE%^Taberna El Caballo feliz%^RESET%^.");
  	set_long(query_short()+"\n\n Estamos en la taberna de ormerod, aqui es onde vienen la gente del pueblpo a "
	"descansar despues de un dia de trabajo, la taberna esta llena de pieles de animales por las paredes"
	" tiene un ambiente agradable.\n");
  	add_item(({"pared","suelo",}),"La estancia esta construida en madera fuerte.");
	// Las cosas especiales de las tabernas
	set_salida(ROOMORMP"cruce_ormerod.c");
  	set_dependiente("/d/faeleen/npc/braum_ormerod.c"); // Patric es polivalente xD tendero, herrero, guildmaster, tabernero (el proximo sera Patric chuloputas)
  	add_cartel(); // Un cartel con los comandos basicos (ya sabeis la mecanica que uso con los carteles, si no miraos la tienda o la herreria
  	add_plato("/baseobs/platos/macarrones"); // con esto anyadimos platos (comida y bebida)
	add_plato("/baseobs/platos/muslos.c");
	add_plato("/baseobs/platos/arroz.c");
	add_plato("/baseobs/platos/huevos.c");
	add_plato("/baseobs/platos/hervido.c");
	add_plato("/baseobs/platos/gazpacho.c");
	add_plato("/baseobs/platos/zumonaranja.c");
	add_plato("/baseobs/platos/cervezaenana.c");
	add_plato("/baseobs/platos/zumomanzana.c");
	add_plato("/baseobs/platos/tuttifrutti.c");
	add_plato("/baseobs/platos/chupito");
	set_calidad(3); // Los "tenedores" del local, de 0 (antro) a 5 (restaurant de lujo)
	// Los ajustes, prohibiciones y permisiones van igual que en las tiendas
	}
