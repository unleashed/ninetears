inherit "/obj/monster";

void setup() {
  set_name("sombra");
      set_short("Sombra");
      set_long(query_short()+"\n"+"Vemos a una sombra amenazante, es incorporea "
	  " no tiene los rasgos definidos, ni piernas, en su lugar tiene una especie "
	  "de bruma algo rara, sus manos son garras afiladas, y no tiene expresion de "
	  "querer hacer amigos. Tiene unos ojos rojos fuertes, parecen estar echos de "
	  "sangre, es lo �nico que puedes divisar en la bruma.\n");
      set_main_plural("sombras");
      add_plural("sombras");
      set_gender(2);
      set_level(7+random(3));
      set_max_hp(query_level() * 8);
  load_chat(10,
  ({
    1, ":susurra algo inteligible.",
  }));
}