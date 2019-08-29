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
		" obliga a seguir adelante Hay un cofre en medio de la sala.\n\n");
	add_item("cofre","Un viejo cofre de madera. Tiene runas y raras "
		 "inscripciones grabadas. Esta cerrado con un candado.\n");
   	add_smell(({"cripta","cadaveres","aire"}),"Hay un olor a muerte que "
   		"te produce nauseas.\n");
   	add_exit("este",ROOMS+"cripta01","door");
   	  	
  	add_clone(ROOMS+"tumulario",random(7));
}

void init() {
	::init();
	add_action("abrir","abrir");
}

int abrir(string str, int mychance)
{
	mychance = TP->query_dex()+random(20);
	if (query_property("abierto")==1) return notify_fail("Parece "
		"que ya han saqueado el cofre.\n");
	if (mychance > 25)
	{
		tell_object(TP,"Consigues abrir el cofre, pero "
			"solo hay unas cuantas telara�as.\n");
		add_property("abierto",1);
		return 1;
	}
	else
	{
		TP->adjust_hp(-random(50));
		tell_object(TP,"Fallas al abrir el candado, y activas "
			"una trampa. Una aguja sale de �l y se te "
			"clava en las manos dolorosamente.\n");
		return 1;
	}
}	