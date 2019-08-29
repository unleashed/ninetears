inherit "/std/outside.c";

void desc_room()
{
	set_long("%^BOLD%^%^RED%^Castillo de Trior%^RESET%^: %^ORANGE%^Almenas%^RESET%^\n\n"
      		"Las almenas del castillo estan llenas de arqueros que defienden la ciudad.\n"
		"ante qualquier posible invasion.\n"
		"Los Guardianes no parecen muy amigables. Vigila con lo que dices\n\n");
	set_short("%^BOLD%^%^RED%^Castillo de Trior%^RESET%^: %^ORANGE%^Almenas%^RESET%^");
		/* dark_mess para oscuridad */
	set_dark_mess("Parece ser que tas has perdido entre tanta oscuridad.\n");
		/* dark_long para cuando es de noche (solo en outsides) */
	set_dark_long("%^BOLD%^%^RED%^Castillo de Trior%^RESET%^: %^ORANGE%^Almenas%^RESET%^ \n\n");
	set_exit_color("CYAN");
  	set_light(60);
     	set_zone("almenas_trior");
}

