//Kryger 2003//
inherit "/obj/monster";

void setup() {
set_name("ni�o");
      set_short("Ni�o");
      set_long("Es un ni�o pequenyo, est� correteando por las calles, y jugando con los amigos, tiene los "
	  "rasgos marcados a pesar de su corta edad, sus ropajes son normales, ni pobres ni lujosos.\n");
      add_alias("ninyo");
      set_main_plural("ninyos");
      add_plural("ninyos");
      set_gender(2);
	   load_chat(20,
            ({
              1,":juega con los amigos",
              1,"'alguien ha visto a mi mama?",
             }));
      set_level(5+random(2));
}
