// Brazalete de la guardia Thalos 
inherit "/obj/armour";

void setup() {
   set_base_armour("brazal_metal");
	set_name("Brazaletes  de la guardia");
	set_short("Brazaletes de la guardia");
	set_long("Es un brazalete, lo usan los guardias para proteger sus brazos de las armas enemigas.\n");
	add_alias("brazalete");
	set_main_plural("brazaletes");
	add_property("race",({"duergar","enano"}));
	add_plural("brazaletes");
}
