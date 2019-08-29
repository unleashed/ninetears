/* Gareth 14.1.03
Minotauro para la quest Khurgar */

inherit "obj/monster";

void setup()
{	set_name("minotauro");
  	set_short("Minotauro");
  	set_long("Una bestia, mezcla de humano y de toro. Sus piernas son igual "
  		 "que las de cualquier humano, pero tienen pezu�as y est�n "
  		 "cubiertas por una piel marron oscura. Tiene unos brazos "
  		 "musculosos, de un color algo mas claro que las piernas. La "
  		 "cabeza es de toro, con los ojos rojos y brillantes, y con unos"
  		 " cuernos retorcidos y puntiagudos.\n");
	set_main_plural("Minotauros");
	set_random_stats(16,28);
  	set_str(28);
  	set_dex(18);
  	set_con(30);
  	set_int(18);
  	set_level(46);
  	set_gender(1);
  	  	
  	load_a_chat(15,
({		1, ":te mira con un gesto de odio, sus ojos brillan intensamente",
		1, ":gira lentanmente alrededor de ti, preparandose para atacar",
}));
	add_clone("/baseobs/armas/hacha_a_dos_manos",1);
	add_clone("/baseobs/armaduras/cota_reforzada",1);
	add_clone("/baseobs/armaduras/guanteletes",1);
	init_equip();
}

void event_enter(object ob) {
	if(!ob->query_living()) return ::event_enter(ob); 
	
	tell_object(ob, "Llegas al final del laberinto y te sorprendes cuando "
			"un minotauro de unos dos metros sale de las sombras "
			"pero, sorprendentemente, no te ataca, sino que se te "
			"queda mirando fijamente, con sus ojos reluciendo.\n",TO);	
}