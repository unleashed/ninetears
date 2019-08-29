inherit "/std/hostal";
#include "../../../path.h"


void setup() {
  	set_short("%^BOLD%^BLUE%^Taberna El Caballo feliz%^RESET%^");
  	set_long(query_short()+"\n\n Estamos en la taberna de rongrond, aqui es onde vienen la gente del pueblo a "
	"descansar despues de un dia de trabajo, la taberna esta llena de pescados disecados y utensilios de pesca, "
	"tiene un ambiente agradable.\n");
  	add_item(({"pared","suelo",}),"La estancia esta construida en madera fuerte.");
	set_salida("/d/faeleen/rooms/rongrond/pueblo/pueblo_rongrond_15.c");
  	set_dependiente("/d/faeleen/npc/tabernero_rongrond.c");
  	add_cartel(); 
  	add_plato("/baseobs/platos/macarrones"); 
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
	set_calidad(3);
	}
