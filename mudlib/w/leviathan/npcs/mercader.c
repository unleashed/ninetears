#define GOLPEAR   "/d/gremios/comandos/golpear.c"
inherit "/obj/monster";

void setup() {
set_name("Mercader de la Atlantida");
set_short("Mercader de la Atlantida");
add_alias("mercader");
add_plural("mercaderes");
set_main_plural("Mercaderes de la Atlantida");
set_random_stats(15,18);
set_con(25);
set_long("Este es un mercader del monton. \n");
add_clone("/d/driade/prueba/obj/cuero_atlante",1);
add_clone("/d/driade/prueba/obj/daga_atlante",1);
init_equip();
adjust_money(2+random(1),"gold");
set_max_hp(100);
set_hp(100);
set_max_gp(100);
set_level(16);
}
