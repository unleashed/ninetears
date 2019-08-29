/* Gareth 01.02.2003
Cripta, quest Khurgar */

inherit "/std/room";
#define ROOMS "/w/gareth/quest/rooms/"

void setup() {
	set_short("%^BLACK%^%^BOLD%^Cripta%^RESET%^");
	set_long(query_short()+"\n\n    Te encuentras en "
		"lo que parece un mausoleo muy antiguo,"
		" repleto de grietas y telaranyas en las paredes. El suelo"
		" esta cubierto por suciedad y cadaveres descompuestos, "
		"algunos cruelmente mutilados. A pesar de su abandono y de"
		" las numeros grietas en paredes y techos, la estructura de"
		" la cripta parece segura, y sientes una curiosidad que te"
		" obliga a seguir adelante. Hay una estatua de piedra gris"
		" en el centro de la sala.\n\n");
	add_item("estatua","Una estatua de piedra de un duergar. Empunya un"
		"impresionante hacha a dos manos, y a sus pies hay un hilo "
		"de sangre seca que corre por el suelo, hasta llegar a un "
		"hueco en el suelo que tiene un aspecto parecido al de la "
		"cabeza de un minotauro. Tiene una inscripcion que dice:\n"
		" GHARZ, SE�OR DE LOS KHURGARS\n");
   	add_smell(({"cripta","cadaveres","aire"}),"Hay un olor a muerte que "
   		"te produce nauseas.\n");
   	add_exit("fuera",ROOMS+"cripta06","door");
}

void init() {
	::init(); 
	add_action("poner_cabeza","poner");
}

int poner_cabeza(string str, object *obs) 
    {
	obs = find_match("Cabeza de Minotauro",TP);
	if(!sizeof(obs)) {
		tell_object(TP,"No tienes ninguna cabeza de Minotauro.\n");
		return 1;
	}
	else
	{
		tell_object(TP,"Colocas la cabeza de Minotauro en el hueco "
			"del suelo, y al momento el hacha de la estatua "
			"comienza a brillar intensamente.\nSorprendentemente"
			", la estatua cobra vida y parece ofrecerte su hacha."
			" La cojes, y la estatua recupera su posicion anterior"
			", aunque ahora no empu�a ningun arma.\n");
		obs[0]->dest_me();
		add_clone("/w/gareth/quest/obs/tharkan",1)->move(TP);
	}
}