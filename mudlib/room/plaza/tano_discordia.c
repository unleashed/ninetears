//Kryger 2003//
inherit "/obj/monster";

void setup() {
          set_name("tano");
          set_short("Tano");
  add_alias("tano");
  add_alias("tano");
          set_main_plural("Tanos");
          add_plural("Tanos");
  set_gender(1);
          set_level(21+random(10));
          set_wimpy(0);
  init_equip();
          set_random_stats(14, 20);
          set_long(query_short()+"\nEs el dependiente y due�o de la unica tienda del campo de la discordia, "
		  "es grande de estatura y corpulencia, y tiene una mirada penetrante. Te vigila bastante, parece "
		  "que no le gusta que le roben.\n");
          adjust_money(random(300), "cobre");
          load_chat(20, ({
          1, ":te mira de reojo.",
		  1, ":coloca unos estantes.",
          1, "'Que vas a comprar?",
					   }));

  }