inherit "/obj/monster";
void setup() { 
set_name("intrepido");
set_short("Aventurero intrepido");
set_main_plural("Aventureros intrepidos");
add_alias("aventureros");
add_alias("intrepidos");

set_long("Un loco humano que busca algo de aventura fuera de "
"su ciudad, esta ducho en tecnicas de combate.\n\n");    
set_race("humano");
set_race_ob("/std/races/human");
set_random_stats(14,18);
set_str(27);
set_level(20);
adjust_money(2+random(15),"silver");

add_clone("/baseobs/weapons/bastard_sword.c",2);
add_clone("/baseobs/armours/leather.c",1);
add_clone("/baseobs/armours/helmet.c",1);
add_clone("/baseobs/armours/cape.c",1);
init_equip(); 

load_a_chat(30,({           1, "'Eso eso, ven ven que te voy a dar",           1, "'Te voy a ensenyar mi destreza con la espada!",           1, "@te hace una finta",}));
}

