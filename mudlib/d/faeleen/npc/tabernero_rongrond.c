inherit "/obj/monster";

void setup() {

    set_name("Klorem");
	set_short("Klorem, el cocinero");
	add_alias("klorem");
	set_race("human");
	set_gender(1);
	set_max_hp(500);
	set_hp(500);
	set_max_gp(150);
	set_level(15+random(5));
	adjust_money(10+random(5),"gold");
	set_long("Vemos a un hombre alto, de gran porte, tiene unos rasgos muy acentuados "+
	", viste bi�n. Es el due�o de la taberna, desde aqui controla todo lo que le pasa a su taberna.\n");
	add_clone("/baseobs/armaduras/manto.c",1);
	add_clone("//baseobs/armas/espada_corta.c",1);
	add_clone("/d/faeleen/obj/camisa.c",1);
	add_clone("/d/faeleen/obj/pantalon.c",1);
	init_equip();
}