inherit "/obj/monster";
void setup() { 
set_name("minero");
set_short("Minero exclavo");
set_main_plural("Mineros");
add_alias("minero");
add_alias("enano");
add_alias("exclavo");
add_plural("mineros");
add_plural("enanos");
set_long("Un sufrido i pobre enano exclavizado "
"por el ejercito orco en alguna invasion a la ciudad "
"enana.\n\n");	
//set_guild_ob("/d/gremios/guerreros/fighter");
set_race("enano");
set_race_ob("/std/races/dwarf");
set_random_stats(10,18);
set_str(27);
set_level(15);
adjust_money(2+random(5),"gold");
add_clone("/w/blastaar/items/cotaac.c",1);
add_clone("/w/blastaar/items/picoac.c",1);
init_equip(); 
load_chat(10, ({           1, "@gime desconsoladamente",           1, "Yo antes era un gran guerrero",           1, "'Ten cuidado, estas cuevas no son como el exterior.", }));
load_a_chat(30,({           1, "'Haz que sea rapido",           1, "'Loados sean los dioses, se acabo mi sufrimiento!",           1, "@intenta defenderse",}));
}
