//Rutseg 1-X-2001

#include "../path.h"
inherit "/obj/monster";

void setup()
{
	set_name("yavahne");
	set_short("Yavahne");
	add_alias("yavahne");
	add_alias("elfo");
	add_alias("elfa");
	add_plural("elfas");
	add_plural("elfos");
	set_main_plural("Doncellas elficas");
	set_long("Es una doncella elfica que se encarga de buscar hierbas y traerlas "
		"al hueco en el arbol, para que todos los elfos puedan disfrutar de sus "
		"beneficios medicinales. Su piel es blanca y suave como un prado nevado, y "
		"sus ojos redondos y plateados como dos lunas.");
	set_al(-1000);
	set_race("Elfo");
	set_gender(2);
	set_guild_ob("/std/guilds/warriors/Edhil_faroth");
	set_guild("Edhil_faroth");
	set_random_stats(12,18);
	set_int(18);
	set_dex(19);
	set_cha(20);
	set_level(24);

	add_clone("baseobs/weapons/dagger",1);
	add_clone(ARMADURA+"cuero_elfico.c",1);
	add_clone(ARMADURA+"cinta_elfica",1);
	init_equip();

	adjust_money(random(6),"electro");
}
void event_enter(object ob, string mensaje, object donde)
{
	if(ob->query_property("bando")>1 || ob->query_timed_property("odiado_ARBRE") && ob->query_guild_name()!="Edhil Faroth")
		TO->attack_ob(ob);
	::event_enter(ob, mensaje, donde);
}
void init()
{
	::init();
	add_attack_spell(60,"proyectil magico mayor",({"/std/spells/wizard/mmmissile","cast_spell",0}));
	add_attack_spell(20,"proyectil de agua",({"/std/spells/wizard/proy_agua","cast_spell",0}));
	add_attack_spell(40,"toque vampirico",({"/std/spells/wizard/vamp_touch","cast_spell",0}));
}
void attack_by(object ob)
{
	if(ob->query_property("bando")==1 && !ob->query_property("odiado_ARBRE"))
		ob->add_timed_property("odiado_ARBRE",1,2000);
	return ::attack_by(ob);
}