inherit "/std/room.c";

void desc_room()
{
	set_long("%^BOLD%^%^RED%^Castillo de Trior%^RESET%^: %^ORANGE%^Torre%^RESET%^\n\n"
      		"Estas en el interior de la Torre Central de la fortificacion.\n"
		" Estas subiendo por una escalera de caracol situada en el centro de la torre sube hasta el ultimo piso.\n"
		" La decoracion es muy simple, no muy de acuerdo de la importancia de la misma\n\n");
	set_short("%^BOLD%^%^RED%^Castillo de Trior%^RESET%^: %^ORANGE%^Torre%^RESET%^");
		/* dark_mess para oscuridad */
	/* set_dark_mess("Parece ser que tas has perdido entre tanta oscuridad.\n");
		// dark_long para cuando es de noche (solo en outsides)
	set_dark_long("%^BOLD%^%^RED%^Castillo de Trior%^RESET%^: %^ORANGE%^Torre%^RESET%^\n\n");
	*/
	set_exit_color("CYAN");
  	set_light(60);
     	set_zone("torre_caracol");
}

