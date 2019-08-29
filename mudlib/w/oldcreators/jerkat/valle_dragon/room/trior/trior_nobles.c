inherit "/std/outside.c";

void desc_room()
{
	set_long("%^BOLD%^%^RED%^Castillo de Trior%^RESET%^: %^BOLD%^%^CYAN%^Pasillo Secundario%^RESET%^\n\n"
      		"Esta es la zona rica de la fortificacion. Aqui los nobles tiene sus pertencias."
		" Vigila porque los ladrones suelen robar por esta zona. Si pillas alguno dale duro"
		" porque llevan muchas cosas encima de sus robos\n\n");
	set_short("%^BOLD%^%^RED%^Castillo de Trior%^RESET%^: %^BOLD%^%^CYAN%^Pasillo Secundario%^RESET%^");
		/* dark_mess para oscuridad */
	set_dark_mess("Parece ser que tas has perdido entre tanta oscuridad.\n");
		/* dark_long para cuando es de noche (solo en outsides) */
	set_dark_long("%^BOLD%^%^RED%^Castillo de Trior%^RESET%^: %^BOLD%^%^CYAN%^Pasillo Secundario%^RESET%^\n\n");
	set_exit_color("CYAN");
	set_light(70);
   	set_zone("trior");
}
