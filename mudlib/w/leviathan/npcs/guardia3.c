#define GOLPEAR   "/d/gremios/comandos/golpear.c"
inherit "/obj/monster";
void init()
{
 ::init();
add_attack_spell(100,"golpear",({"std/commands/golpear.c","golpear",1}));
add_attack_spell(100,"drain",({"std/commands/drain.c","drain",1}));
}


void setup() {
set_name("Vigilante de la Atlantida");
set_short("vigilante");
add_alias("vigilante");
add_plural("vigilantes");
set_guild("magobueno");
set_gender(1);
set_main_plural("vigilantes");
set_str(20);
set_con(40);
set_dex(18);
set_int(18);
set_wis(18);
set_cha(18);
set_long("Este es uno de los guardias que controlan los accesos a la ciudad. \n");
add_clone("/d/driade/prueba/obj/ammuleto_atlante",1);
add_clone("/d/driade/prueba/obj/anillo_atlante",1);
add_clone("/d/driade/prueba/obj/cota_atlante",1);
add_clone("/d/driade/prueba/obj/botas_atlante",1);
add_clone("/d/driade/prueba/obj/capa_atlante",1);
add_clone("/d/driade/prueba/obj/espada_atlante",1);
add_clone("/d/driade/prueba/obj/escudo_atlante",1);
add_clone("/d/driade/prueba/obj/brazalete_atlante",1);
add_clone("/d/driade/prueba/obj/guante_atlante",1);
add_clone("/d/driade/prueba/obj/pantalon_atlante",1);
add_clone("/d/driade/prueba/obj/yelmo_atlante",1);
init_equip();
set_max_hp(500);
set_hp(500);
set_max_gp(2000);
set_level(51);
set_heart_beat(2);
set_thac0(-115);
set_aggressive(0);
}
