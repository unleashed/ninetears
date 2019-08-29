inherit "/obj/armour.c";

void setup() {
	set_base_armour("completa"); 
	set_name("coraza del caos");
	add_alias("coraza");
	add_alias("caos");
	set_short("%^BOLD%^BLACK%^Coraza del %^RED%^CaoS%^RESET%^");
	set_long(" Esta Coraza fue un regalo de Niclaus a sus guardianes, la coraza "
	"lleva el simbolo del Latigo de Fuego en el frontal, realizado en mithril y oro. "
	"Sus hombros estan cubiertos por afilados pinchos, asi como sus codos y rodillas "
	"preparados para asestar terrorificos golpes. Son famosas por que son practicamente  "
	"invulnerables a casi cualquier arma.\n\n");
	set_main_plural("%^BOLD%^BLACK%^Corazas del %^RED%^CaoS%^RESET%^");
	add_plural("corazas");
	add_plural("caos");
	set_enchant(100);
	add_timed_property("cold",100,999999999999999999);
	add_timed_property("fire",100,999999999999999999);
	}
