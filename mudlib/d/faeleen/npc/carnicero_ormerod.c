//Kryger 2003//
inherit "/obj/monster";

void setup() {
          set_name("carnicero");
          set_short("Carnicero");
  add_alias("carnicero");
  add_alias("carnicero");
          set_main_plural("Carniceros");
          add_plural("carniceros");
  set_gender(1);
          set_level(21+random(10));
          set_wimpy(0);
  init_equip();
          set_random_stats(14, 20);
          set_long(query_short()+"\nEs el dependiente y due�o de la carniceria de ormerod, es una "
		  "persona grande, alta y fuerte, es robusto y simp�tico con los clientes, lo ves partiendo "
		  "carne con el hacha, menudo golpes le da, por un momento piensas en que es mejor no tenerlo "
		  "por enemigo.\n");
          adjust_money(random(30), "plata");
          load_chat(20, ({
          1, ":te mira a los ojos.",
		  1, ":coloca la carne.",
          1, "'Que te pongo?",
					   }));

  }