//Kryger 2003//

inherit "/obj/monster";


void setup() {
      set_name("Capitan orco");
      set_short("Capitan orco");
      set_main_plural("Capitanes orcos");
      add_alias("orco");
	  add_plural("orcos");
	  add_plural("capitanes");
      set_race("orco");
      set_level(15+random(6));
      set_wimpy(0);
      set_long(query_short()+"\n"+"Esto es un Capitan orco, un agresivo mamifero carnivoro... incluso puede que canibal.Es de "
	  "gran tama�o, mas de 2 metros diria, es grande de corpulencia e igual de repugnante que el resto "
	  "de su raza, no tiene grandes diferencias a la vista.\n");
      adjust_money(random(10), "oro");
      set_aggressive(1);
	  add_move_zone("zona_clara");
      set_move_after(13,5);
	  add_clone("/baseobs/armas/hacha.c",2);
	  add_clone("/baseobs/armaduras/armadura_de_cuero.c",1);
	  add_clone("/baseobs/armaduras/yelmo.c",1);
      load_a_chat(30,
         ({
               1, ":te gru�e",
               1, "' %^RED%^Grooaakk! %^RESET%^Fuera de nueztro valle!!
			   1, "' %^RED%^Grooakk! %^RESET%^Vamoz ezkoria no oz kedeiz atraz!!
          }));
      set_join_fight_mess("Un orco se dispone a atacar exclamando: Waaagh, muerte i deztrukzion!\n");
	this_object()->init_equip();
} /* setup() */
