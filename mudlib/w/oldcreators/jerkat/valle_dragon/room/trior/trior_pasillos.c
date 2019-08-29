inherit "/std/outside.c";

void desc_room()
{
	set_long("%^BOLD%^%^RED%^Castillo de Trior%^RESET%^: %^ORANGE%^Pasillos%^RESET%^\n\n"
      		"Te encuentras en las calles de la ciudad: vagabundos pidiendo dinero,"
		" gatos y perros peleandose y las casas de los habitantes, los que se lo"
		"pueden permitir\n\n");
	set_short("%^BOLD%^%^RED%^Castillo de Trior%^RESET%^: %^ORANGE%^Pasillos%^RESET%^");
		/* dark_mess para oscuridad */
	set_dark_mess("Parece ser que tas has perdido entre tanta oscuridad.\n");
		/* dark_long para cuando es de noche (solo en outsides) */
	set_dark_long("%^BOLD%^%^RED%^Castillo de Trior%^RESET%^: %^ORANGE%^Pasillos%^RESET%^\n\n");
	set_exit_color("CYAN");
	set_light(60);
   	set_zone("trior");
}
