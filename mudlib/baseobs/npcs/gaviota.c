//Kryger 2003//
inherit "/obj/monster";

void setup() {
set_name("gaviota");
      set_short("Gaviota");
      set_long(query_short()+"\n\n Ves una gaviota, como muchas de las que habitan el lugar, "
	                         "tiene un pelaje blanco y su pico es naranja, tiene un tama�o "
							 "consiedrable, pero aun asi, parece inofensiva, de todas formas "
							 "m�s vale no provocarla.\n");
      set_main_plural("Gaviotas");
	  add_plural("gaviotas");
      set_gender(2);
	  load_chat(20,
            ({
              1,":hace un vuelo raso.",
		     }));
      set_level(7+random(5));
}
