//Kryger 2003//
inherit "/obj/monster";

void setup() {
          set_name("rasputin");
          set_short("Rasputin");
  add_alias("rasputin");
  add_alias("rasputin");
          set_main_plural("Rasputines");
          add_plural("rasputines");
  set_gender(1);
          set_level(21+random(10));
          set_wimpy(0);
  init_equip();
          set_random_stats(14, 20);
          set_long(query_short()+"\nEs el due�o de la herreria, es de complexion grande, alto y fuerte"
		  "tiene los rasgos muy marcados y el sudor le gotea por todos lados.\n");
          adjust_money(random(300), "cobre");
          load_chat(20, ({
          1, ":golpea en el yunque.",
		  1, ":ordena la estanteria.",
          1, "'Que quereis reparar?",
					   }));

  }