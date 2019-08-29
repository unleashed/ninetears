// Ene '02 Ogro version 1 by Tyrael

inherit "/obj/monster";

void setup() {
  set_name("Armandin");
  add_alias("chigrero");
  add_alias("armandin");
  set_al(10000);
  set_short("Armandin");
  set_race("Armandin");
  set_language("common");
  set_level(50+random(500));
  set_max_hp(3000);
  set_max_gp(3000);
  set_random_stats(60, 68);
  set_ac(-400);
  set_thac0(-70);
  set_gender(1);
  set_long("Ante ti tienes al camarero de la taberna, que atentamente atiende a sus "
	   "clientes sin importarle apenas el grado de alcoholismo que estos tengan.\n");
  set_join_fight_mess("Un enorme Ogro defiende su morada de TI!\n");
  set_aggressive(3);
	//set_damage_bon(25); no existe
	adjust_tmp_damage_bon(25);
	add_clone("/room/camino_avalon/objs/tronco",1);
	add_clone("/d/driade/leviathan/obj/botas.c",1);
	init_equip();
} /* setup() */

