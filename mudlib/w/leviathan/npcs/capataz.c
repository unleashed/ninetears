#define GOLPEAR   "/d/gremios/comandos/golpear.c"
inherit "/obj/monster";
#include "../path.h";

void setup() {
set_name("Capataz");
set_short("Capataz");
add_alias("capataz");
add_plural("capataces");
set_gender(1);
set_main_plural("Capataces");
set_str(20);
set_con(40);
set_dex(17);
set_int(8);
set_wis(8);
set_cha(16);
set_long("Este es uno de los siervos de rango medio de LeviAthaN, se ocupa de controlar a los esclavos para que hagan su "+
		"trabajo adecuadamente, y de darles unos latigazos cuando estos se sienten desmotivados. No dudaran "+
		"ni tan siquiera en matarlos si es necesario para que se ganen el pan duro de cada dia.\n");
add_clone(OBJ"cotacapataz",1);
add_clone(OBJ"latigo",1);
init_equip();
set_max_hp(500);
set_hp(500);
set_max_gp(200);
set_level(31);
set_heart_beat(2);
set_thac0(-115);
set_aggressive(666);
load_chat(50, ({ 1, "'trabaja mas rapido esclavo!!.",
                 1, "'hoy aun no mate a madie.. a ver quien es el primero!.",
                 1, "'Te retoh! rufian! malandrin!.",
                 1, "'A ver cuando viene la remesa de latigos de 7 colas."}));
add_move_zone("esclavosleviathan");
set_move_after(10,6);
}
