inherit "/obj/monster";

void setup() {
      set_name("esclavo");
      set_race_ob("/std/races/human");
      add_alias("esclavo");
      set_main_plural("esclavos");
      add_plural("esclavos");
      set_al(-10);
      set_random_stats(10, 17);
      set_cha(6+random(10));
      set_level(5+random(5));
      set_wimpy(10);
      add_move_zone("esclavosleviathan");
      set_short("esclavo");
      set_long("Es un esclavo destinado bastante afortunado, puesto que ha sido puesto al servicio del Templo "+
		      "de Leviathan, lo cual mas que un suplicio, es un Don Divino.\n");
      load_chat(50, ({ 1, "'guardia! dame unos latigazos que me siento desmotivado!.", 
                       1, "'esto es vida! y no la de Keroon!.",
                       1, "'Que Leviathan le acoja en sus fosas cumunes!.",
                       1, "'Vos venis a morir de muy lejos buen senyor?."}));
      add_clone("/d/driade/prueba/obj/martillo.c",1);
      set_move_after(10,6);
      ::init_equip();
} /* setup() */
