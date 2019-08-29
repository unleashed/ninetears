/*       Gareth 10.02.2003
Laberinto del Minotauro, quest Khurgar */

inherit "/std/room";
#define ROOMS "/w/gareth/comandos/"

void setup() {
	set_short("%^BLACK%^%^BOLD%^Laberinto del Minotauro%^RESET%^");
	set_long(query_short()+"\n\n    Estas en un laberinto excavado "
		"en la roca, no se sabe por quien. Los corredores que "
		"lo forman estan ligeramente iluminados por la luz que "
		"atraviesa las grietas del techo, y por antorchas que "
		"cuelgan en las paredes. No parece haber ningun ser vivo"
		" por los alrededores y todo esta en silencio.\n    Hay un"
		" hueco abierto en la pared, de tama�o suficiente para "
		"que pueda pasar alguien pequenyo.\n\n");
   	add_sound(({"laberinto","aire"}),"Todo el laberinto esta sumido en "
   		"el silencio.\n");
   	add_exit("sudoeste",ROOMS+"laberinto14","standard");
}

void init()
    {
	::init();
	add_action("pasa_grieta","entrar");
    }
    
int pasa_grieta(string str)
    {
    	if (str == "hueco")
    	{
    		if (TP->query_race()!="duergar") return notify_fail("Intentas pasar por la grieta, pero no cabes.\n");
    		tell_object(TP,"Te deslizas a traves de la pequenya grieta y "
    		"llegas a la siguiente sala.\n");
    		return 1;
    	}
    }
