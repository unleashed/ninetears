inherit "/obj/monster";

void setup(){
	set_name("guardian");
	set_short("Guardian del %^BOLD%^%^BLACK%^CaoS%^RESET%^");
	set_long(" Un guardian humano de dos metros de alto e imponente musculatura, "
	"esta rodeado por un aura negra que te infunde un gran respeto, incluso miedo. "
	"Entre toda la negrura de su ser solo puedes vislumbrar los ojos de un rojo "
	"centelleante que te miran de forma penetrante.\n");
	set_main_plural("Guardianes del %^BOLD%^%^BLACK%^CaoS%^RESET%^");
	add_alias("caos");
	add_plural("caos");
	add_plural("guardianes");
	set_gender(1);
	set_level(50+random(5));
	set_random_stats(19, 20);
	set_wimpy(0);
	set_max_hp(query_level() * 500);
	set_hp(query_max_hp());
	set_max_gp(query_level() * 500);
	set_gp(query_max_gp());
	set_max_ep(query_level() * 500);
	set_gp(query_max_gp());
	load_chat(30,({
	2, "'Dame Una Razon Y Te Destripare.",
	1, ":permanece rigido, parece una estatua.",
	3, "'Proteger a Niclaus y Esta Fortaleza Es Mi Deber! y Lo Cumplire Con Mi Vida.",
	3, "'Como Me Gustaria Empalar Con Mi Espada A Ese Sucio Elfo de Drakzten!",
	3, ":practica algunos hechizos.",}));
	load_a_chat(100,({
	3, "'Muy Bien! Ahora Sufriras El Poder del Mal!",
	3, ":comienza a recitar una serie de versos en alguna lengua oscura.",
	3, "'Huye De Aqui Como El Cobarde Que Eres O Muere!!",
	3, ":te mira con los ojos inyectados en sangre.",
	2, "'Me Comere Tus Tripas Sucio Bastardo!",}));
	add_clone("/w/niclaus/workroom/items/firesword.c",2);
	
	init_equip();
	adjust_money(100,"platino");
}