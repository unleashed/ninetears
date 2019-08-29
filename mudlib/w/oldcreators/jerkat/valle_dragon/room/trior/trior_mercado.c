inherit "/std/outside.c";

void desc_room()
{
	set_long("%^BOLD%^%^RED%^Castillo de Trior%^RESET%^: %^ORANGE%^Mercado%^RESET%^\n\n"
      		"Estas en el mercado de Trior. Es muy pequenyo y los pocos comerciantes"
		" que hay intentan vender lo que pueden a viajeros como tu e intentar"
		"que los ladrones no les roben\n\n");
	set_short("%^BOLD%^%^RED%^Castillo de Trior%^RESET%^: %^ORANGE%^Mercado%^RESET%^");
		/* dark_mess para oscuridad */
	set_dark_mess("Parece ser que tas has perdido entre tanta oscuridad.\n");
		/* dark_long para cuando es de noche (solo en outsides) */
	set_dark_long("%^BOLD%^%^RED%^Castillo de Trior%^RESET%^: %^ORANGE%^Mercado%^RESET%^\n\n");
	
	set_exit_color("CYAN");
	set_light(70);
   	set_zone("mercado_trior");
}
