//Kryger 2003//
inherit "/obj/monster";

void setup() {
set_name("cangrejo");
      set_short("Cangrejo");
      set_long(query_short()+"\n\n Este es un cangrejo de mar, no es enorme, pero por su tama�o "
	                         "compardo con el resto de cangrejos, podria decirse que es grande, "
							 "tiene unas pinzas grandes y amenazantes, m�s te vale no acercarte "
							 "mucho a ellas.\n");
      set_main_plural("Cangrejos");
	  add_plural("cangrejos");
      set_gender(2);
	  load_chat(20,
            ({
              1,":cierra las pinzas rapidamente.",
		     }));
      set_level(7+random(5));
}
