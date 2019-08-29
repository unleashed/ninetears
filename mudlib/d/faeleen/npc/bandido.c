//Kryger 2003//

inherit "/obj/monster";


void setup() {
      set_name("bandido");
      set_short("Bandido");
      set_main_plural("Bandidos");
      add_alias("bandido");
	  add_plural("bandidos");
	  add_plural("bandidos");
      set_race("humano");
      set_level(10+random(6));
      set_wimpy(0);
      set_long(query_short()+"\n\n Es un bandido de los muchos que se pueden encontrar en esta "
            "zona. Se gana la vida asaltando a las personas y robandole "
            "todas sus pertenencias. Son peligrosos, sobre todo en las "
            "emboscadas.\n");
      adjust_money(random(6), "plata");
      set_aggressive(0);
	  add_move_zone("bosque_bandidos");
	  add_clone("/baseobs/armas/daga.c",1);
	  add_clone("/baseobs/armaduras/armadura_de_cuero.c",1);
	  add_clone("/baseobs/armaduras/manto.c",1);
      load_a_chat(30,
         ({
               1, ":te vigila disimuladamente",
               1, "' la bolsa o la vida!",
          }));
	this_object()->init_equip();
} /* setup() */
