//Kryger 2003//
inherit "/obj/monster";

void setup() {
set_name("tortuga");
      set_short("Tortuga");
      set_long(query_short()+"\n\n Ves una tortuga de mar, es grande, muy grande dirias tu, "
							 "tiene un metro de ancho por uno y medio de largo, su caparaz�n "
							 "es duro como una roca, parece inofensiva, pero de todas formas "
							 "es mejor no provocarla.\n");
      set_main_plural("Tortugas");
	  add_plural("tortugas");
      set_gender(2);
	  load_chat(20,
            ({
              1,":esconde la cabeza.",
		     }));
      set_level(10+random(5));
}
