//Kryger 2003//
inherit "/obj/monster";

void setup() {
          set_name("theden");
          set_short("Theden");
  add_alias("theden");
  add_alias("theden");
          set_main_plural("Thedens");
          add_plural("Thedens");
  set_gender(1);
          set_level(21+random(10));
          set_wimpy(0);
  add_clone("/w/aprendizaje/jamonero",1);
  init_equip();
          set_random_stats(14, 20);
          set_long(query_short()+"\nEs el dependiente del local,Turin lo hizo a imagen y semjanza suya porque "
		  "no confiaba en nadie m�s para dejarle el negocio, es bajo pero fuete, no se le ve un enemigo muy "
		  "facil de batir.\n");
          adjust_money(random(300), "cobre");
          load_chat(20, ({
          1, ":te limpia la mesa.",
          1, "'Que vas a tomar?",
					   }));

  }