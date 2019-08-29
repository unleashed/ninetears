inherit "/std/outside.c";

void setup()
{
	set_long("%^BOLD%^%^RED%^Castillo de Trior%^RESET%^: %^BOLD%^%^CYAN%^Entrada%^RESET%^\n\n"
      		"Es la entrada al Castillo de Trior.\n"
		"Unas puertas de gran embergadura las cuales dan una gran seguridad en"
		"el interior."
		"Los Guardianes no parecen muy amigables. Vigila con lo que dices\n\n");
	set_short("%^BOLD%^%^RED%^Castillo de Trior%^RESET%^: %^BOLD%^%^CYAN%^Entrada%^RESET%^\n\n");
	set_exit_color("CYAN");
   	set_light(70);
   	set_dark_mess("Estas dentro del castillo pero no sabes en que parte.\n");
		/* dark_long para cuando es de noche (solo en outsides) */
   	set_dark_long("%^BOLD%^%^RED%^Castillo de Trior%^RESET%^ \n\n");
   	set_zone("trior");
	add_exit("fuera","w/jerkat/valle_dragon/room/valle_38","door");	
	add_exit("este","w/jerkat/valle_dragon/room/trior/mercado_05","road");
	add_exit("escaleras","w/jerkat/valle_dragon/room/trior/almenas_06","door");
	add_clone("w/jerkat/valle_dragon/nopc/guardia_trior",4);
}
