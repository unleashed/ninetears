//Kryger 2003//
inherit "/obj/monster";

void setup() {
   set_name("mujer");
      set_short("Mujer");
      set_long("Es una habitante de Rongrond, es de estatura media, ojos claros y pelo oscuro, tiene un aire "
	  "de campesina, sus ropajes no son lujosos por lo que observamos que es de una familia de econom�a media.\n");
      add_alias("mujer");
      set_main_plural("mujeres");
      add_plural("mujeres");
      set_gender(1);
	  load_chat(20,
            ({
              1,":te mira de reojo.",
              1,"'donde estara mi ninyo?",
             }));
      set_level(10+random(3));
}
