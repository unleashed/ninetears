#define GOLPEAR   "/d/gremios/comandos/golpear.c"
inherit "/obj/monster";

void setup() {
set_name("Ciudadano de la Atlantida");
set_short("Ciudadano de la Atlantida");
add_alias("ciudadano");
add_plural("ciudadanos");
set_main_plural("Ciudadanos de la Atlantida");
set_random_stats(15,18);
set_con(25);
set_long("Este es un ciudadano del monton. \n");
add_clone("/d/driade/prueba/obj/cuero_atlante",1);
add_clone("/d/driade/prueba/obj/daga_atlante",1);
init_equip();
adjust_money(1+random(1),"gold");
set_max_hp(100);
set_hp(100);
set_max_gp(100);
set_level(16);
}
