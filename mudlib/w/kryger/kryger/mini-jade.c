//Kryger 2003//
inherit "/obj/monster";

void setup() {
          set_name("Mini-Jade");
          set_short("Mini-Jade");
  add_alias("mini");
  add_alias("mini-jade");
          set_main_plural("Mini-Jades");
          add_plural("Mini-Jades");
  add_plural("mini-jades");
  add_plural("minis");
  set_gender(1);
          set_level(21+random(10));
          set_wimpy(0);
  init_equip();
          set_random_stats(14, 20);
          set_long(query_short()+"\nEs la encargada del Banco, es una replica exacta a la gran diosa Jade "
		  "en ella ha puesto todo su empe�o y avaricia para que guarde bi�n el dinero de los tantos viajeros "
		  "que por este campo pasan\n");
          adjust_money(random(2), "cobre");
          load_chat(20, ({
          1, ":cuenta el dinero una y otra vez.",
          1, "'no Vilat, aqui todos pagan intereses, asi que no te invito",
					   }));

  }