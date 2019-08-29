inherit "/std/outside.c";

void desc_room()
{
    set_long("%^BOLD%^%^RED%^Castillo de Trior%^RESET%^\n\n"
      "El Valle parece abrirse entre dos montanyas de gran embergadura.\n"
	"Estas en un pequenyo camino que atraviesa el denso bosque"
	"y ves al margen derecho un pequenyo riachuelo que te acompanya"
	"a lo largo del camino ascendiente hasta el fondo del valle.\n "
	"Debes apresurarte si no quieres que la noche se te heche encima\n\n");
   set_exit_color("CYAN");
   set_light(70);
   set_short("%^BOLD%^%^RED%^Castillo de Trior%^RESET%^");
   set_dark_mess("Estas dentro del castillo pero no sabes en que parte.\n");
	/* dark_long para cuando es de noche (solo en outsides) */
   set_dark_long("%^BOLD%^%^RED%^Castillo de Trior%^RESET%^ \n\n");
   set_zone("trior");
}      