#define GOLPEAR   "/d/gremios/comandos/golpear.c"
inherit "/obj/monster";

void setup() {
set_name("Perro Amarillo");
set_short("Perro Amarillo");
add_alias("perro");
add_plural("perros");
set_main_plural("Perros Amarillos");
set_random_stats(15,18);
set_con(25);
set_long("Este es un perro del monton. \n");
set_max_hp(100);
set_hp(100);
set_max_gp(100);
set_level(16);
}
