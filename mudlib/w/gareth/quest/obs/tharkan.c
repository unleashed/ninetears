//Gareth 14.1.2003

inherit "/obj/weapon";

void setup()
{
	set_base_weapon("hacha_guerra");
	set_name("tharkan");
	set_short("%^WHITE%^%^BOLD%^Tharkan, el Hacha%^RESET%^");
	set_main_plural("hachas %^WHITE%^%^BOLD%^Tharkan%^RESET%^");
	set_long("Un Hacha de Guerra de doble hoja, que por su apariencia "
		 "tiene una gran calidad. El mango mide un metro, y est� "
		 "hecho de madera reforzada con cuero negro. La hoja es de"
		 " acero, muy afilada y con los filos redondeados. Tiene "
		 "unas runas que no conoces grabadas en la hoja.\n");
	add_alias("hacha");
	add_plural("hachas");
	set_enchant(2);
}