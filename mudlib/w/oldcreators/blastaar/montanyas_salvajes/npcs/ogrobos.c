inherit "/obj/monster.c";
void setup() {    
set_name("ogro");
set_race("ogro");
set_short("ogro del bosque");
set_long("Una criatura realmente repugnante,cubierta de babas "
"y de pelo por todas partes, el ogro mide "
"unos tres metros y medio de alto y casi metro y medio "
"de hombro a hombro, mejor no meterse con el.\n");
add_alias("ogro");
add_alias("hambriento");
set_main_plural("Ogros del bosque");
add_plural("ogros");
set_random_stats(14,18);
set_str(30);
set_con(40);
set_gender(1+random(2));
add_hated("race",({"human","elf","half-elf","Gnomo","Dwarf"}));
add_property("magic",20);
add_property("fire",-30);  
add_property("electrical",40);
add_property("cold",40);
set_level(20+random(5));
set_max_hp(250+random(200));
set_al(860);
set_alignment(860);
add_clone("/w/blastaar/items/arbol.c",1);
init_equip();
}


