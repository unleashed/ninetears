inherit "/std/outside.c";

void desc_room()
{
	set_long("%^BOLD%^%^RED%^Castillo de Trior%^RESET%^: %^ORANGE%^Torre%^RESET%^\n\n"
      		"La Torre del Gran Noble esta situada en medio de la fortificacion.\n"
		" Goza de una esplendida hermosura y es tan grande que tus ojos no.\n"
		" logran ver la punta, donde la leyenda cuenta que aguardan grandes tesoros\n\n");
	set_short("%^BOLD%^%^RED%^Castillo de Trior%^RESET%^: %^ORANGE%^Torre%^RESET%^");
		/* dark_mess para oscuridad */
	set_dark_mess("Parece ser que tas has perdido entre tanta oscuridad.\n");
		/* dark_long para cuando es de noche (solo en outsides) */
	set_dark_long("%^BOLD%^%^RED%^Castillo de Trior%^RESET%^: %^ORANGE%^Torre%^RESET%^\n\n");
	set_exit_color("CYAN");
  	set_light(60);
     	set_zone("torre_exterior");
}

