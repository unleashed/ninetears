//Gareth 3.11.02

#include "/d/inframundo/path.h"
inherit "/std/inframundo";

void setup() {
	set_short("%^BOLD%^Callejon del %^RED%^%^BOLD%^Estrangulamiento%^RESET%^");
	set_long(query_short()+"\n Atraviesas la puerta y entras en un callejon sumido en la oscuridad. No ves nada, excepto un peque�o fuego azul chisporroteando, al final del callejon. De vez en cuando logras ver una sombra que se mueve aqui y alla, pero no adivinas que puede ser.\n\n");
   	add_sound(({"habitacion","sala","aire"}),"Escuchas unos pasos casi inaudibles, que se confunden con los lamentos de las almas que moran aqui.\n");
   	add_exit("oeste",ROOMS+"callejon2","door");
   	add_clone(NPCS+"asesino",2);
}

void init() {
	::init();
	add_action("tocar_fuego","tocar"); }
int tocar_fuego(string str) {
   	if(str == "fuego") {
	tell_object(TP,"Te acercas a la peque�a llama, y posas tu mano sobre ella sin que te des cuenta. Unas fuertes manos aparecen rapidamente de entre las sombras y agarran tu cuello, apretando fuertemente, sin que nada puedas hacer. Las manos siguen apretando hasta que casi no puedes respirar, y en ese momento te sueltan y desaparecen.\n");
	tell_room(TO,this_player()->query_cap_name()+" posa sus manos sobre el fuego y unas manos le agarran del cuello, intentando estrangularlo.\n",TP);
	return 1;
		return notify_fail("Tocar que?\n");
}
}