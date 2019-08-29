#define GOLPEAR   "/d/gremios/comandos/golpear.c"
inherit "/obj/monster";
void init()
{
 ::init();
add_attack_spell(100,"golpear",({"std/commands/golpear.c","golpear",1}));
add_attack_spell(50,"proy_magico_mayor", ({"/d/gremios/hechizos/escuelas/invocacion/","proy_magico_mayor"
,1}));
}


void setup() {
set_name("ghorothor");
set_short("Ghorothor Caudillo del Mal");
set_gender(1);
set_main_plural("Personas parecidas a Ghorothor");
set_str(70);
set_con(40);
set_dex(40);
set_int(40);
set_wis(40);
set_cha(40);
set_long("Es uno de los orcos mas fornidos y grandes "
"que se recuerdan, su voracidad y fiereza en combate "
"son legendarias. La leyenda cuenta que su batallon "
"fue uno de los principales causantes de la caida "
"de la ciudad de humanos y que el solo elimino a mas "
"de cien hombres a golpe de maza.\n");
add_clone("/w/blastaar/items/anillonib.c",1);
add_clone("/w/blastaar/items/mazadeacero.c",1);
add_clone("/w/blastaar/items/taparrabos.c",1);
add_clone("/w/blastaar/objetos/anillonib.c",1);
init_equip();
set_max_hp(4000);
set_max_gp(4000);
set_level(70);
set_heart_beat(2);
set_thac0(-115);
set_aggressive(5);
}
/*
void heart_beat()
{
object *i;
if (sizeof(i=query_attacker_list()))
{
GOLPEAR->golpear(i[random(sizeof(i))]->query_name(), TO);
}
::heart_beat();
}*/
