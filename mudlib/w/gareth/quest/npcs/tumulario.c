/* Gareth 14.1.03
Tumulario para la quest Khurgar */

inherit "obj/monster";

void setup()
{	set_name("tumulario");
  	set_short("Tumulario");
  	set_long("Una sombra oscura, vestida con una cota abollada y "
  		 " vieja, y un yelmo oxidado. Sus brazos est�n tapados"
  		 " con una capa ra�da, pero unas garras viscosas y "
  		 "putrefactas se ven por debajo de la capa.\n");
	set_main_plural("Tumularios");
  	add_alias("zombie");
  	add_alias("muerto");
  	add_plural("zombies");
  	set_level(20+random(20));
  	set_random_stats(15,19);
  	  	  	
  	load_a_chat(15,
({		2, "'No molestes al Rey, intruso",
		1, "'Sal de aqui, mortal, o sufriras el castigo de la vida eterna",
                1, "'Debemos proteger a nuestro Rey, debemos cumplir nuestro juramento...",
                2, ":se acerca a ti y te toca con sus garras. Un frio insoportable te "
                   "recorre el cuerpo, con lo que te entran ganas de salir a correr",
}));
	add_clone("/baseobs/armas/hacha",1);
	add_clone("/baseobs/armaduras/cota",1);
	add_clone("/baseobs/armaduras/casco",1);
	add_clone("/baseobs/escudos/escudo",1);  
	init_equip();
}

void event_enter(object ob, string message) {
	if(!ob->query_living()) return ::event_enter(ob, message); 
	attack_by(TP);
} 