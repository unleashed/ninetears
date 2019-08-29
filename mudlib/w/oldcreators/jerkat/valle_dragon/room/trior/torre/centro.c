inherit "/std/room.c";

void setup()
{
	set_long("%^BOLD%^%^RED%^Castillo de Trior%^RESET%^: %^ORANGE%^Torre%^RESET%^\n\n"
      		"Estas en la puerta de la Gran Torre del Castillo de Trior.\n"
		" Dos Guardias te impiden la entrada a menos que seas reconocido por el Gran.\n"
		" Senyor o que por otra parte les mates...\n\n");
	set_short("%^BOLD%^%^RED%^Castillo de Trior%^RESET%^: %^ORANGE%^Torre%^RESET%^");
		/* dark_mess para oscuridad */
	/* set_dark_mess("Parece ser que tas has perdido entre tanta oscuridad.\n");
		// dark_long para cuando es de noche (solo en outsides)
	set_dark_long("%^BOLD%^%^RED%^Castillo de Trior%^RESET%^: %^ORANGE%^Torre%^RESET%^\n\n");
	*/
	set_exit_color("CYAN");
  	set_light(60);
     	set_zone("torre_centro");
     	add_exit("este","w/jerkat/valle_dragon/room/trior/torre/torre_02","door");
       	add_exit("oeste","w/jerkat/valle_dragon/room/trior/torre/torre_04","door");
       	add_exit("arriba","w/jerkat/valle_dragon/room/trior/torre/nivel1/centro","door");
}

