inherit "/std/outside.c";

void desc_room()
{
	set_long("%^BOLD%^%^RED%^Castillo de Trior%^RESET%^: %^BOLD%^%^CYAN%^Caseta de los Guardias%^RESET%^\n\n"
      		"Te encuentras en la Caseta de los guardias. Aqui los vigilantes de trior decansan."
		"Tambien guardan las armas y armaduras. Estan preparados para la batalla"
		"Observas mucho moviento...\n\n");
	set_short("%^BOLD%^%^RED%^Castillo de Trior%^RESET%^: %^BOLD%^%^CYAN%^Caseta de los Guardias%^RESET%^");
		/* dark_mess para oscuridad */
	set_dark_mess("Parece ser que tas has perdido entre tanta oscuridad.\n");
		/* dark_long para cuando es de noche (solo en outsides) */
	set_dark_long("%^BOLD%^%^RED%^Castillo de Trior%^RESET%^: %^BOLD%^%^CYAN%^Caseta de los Guardias%^RESET%^\n\n");
	set_exit_color("CYAN");
	set_light(70);
   	set_zone("trior");
}
