//Kryger 2003//
inherit "/obj/monster";

void setup() {
          set_name("Mini-Turin");
          set_short("Mini-Turin");
  add_alias("mini");
  add_alias("mini-turin");
          set_main_plural("Mini-Turines");
          add_plural("Mini-Turines");
  add_plural("mini-turines");
  add_plural("minis");
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
          1, ":te lame las botas.",
          1, "'Que vas a tomar?",
					   }));

  }