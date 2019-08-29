//Kryger 2003//

inherit "/obj/monster";


void setup() {
      set_name("Orco");
      set_short("Orco");
      set_main_plural("Orcos");
      add_alias("orco");
	  add_plural("orcos");
	  add_plural("orcos");
      set_race("orco");
      set_level(10+random(6));
      set_wimpy(0);
      set_long(query_short()+"\n"+"Esto es un orco, un agresivo mamifero carnivoro... incluso puede que canibal.Es de "
	  "gran tama�o, mas de 2 metros diria, es grande de corpulencia e igual de repugnante que el resto "
	  "de su raza, no tiene grandes diferencias a la vista.\n");
      adjust_money(random(3), "oro");
      set_aggressive(1);
	  add_clone("/baseobs/armas/hacha.c",1);
	  add_clone("/baseobs/armaduras/armadura_de_cuero.c",1);
	  add_clone("/baseobs/armaduras/manto.c",1);
      load_a_chat(30,
         ({
               1, ":gru�e",
               1, ": %^RED%^Grooaakk! %^RESET%^Fuera de aki!!",
          }));
      set_join_fight_mess("Un orco se dispone a atacar exclamando: Waaagh, muerte i deztrukzion!\n");
	this_object()->init_equip();
} /* setup() */
