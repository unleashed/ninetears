//Kryger 2003//
inherit "/std/room.c";

void setup()
{
	set_short("%^BOLD%^RED%^Age of %^BLACK%^Darkness: %^RESET%^RED%^Entrada%^RESET%^");
	set_long(query_short()+"\n\n Estamos en la entrada al clan Age of Darkness es una entrada bi�n "
	                       "discreta y dificil de ver a simple vista, la maleza cubre casi toda la "
			       "estancia. Los colores de esta son muy parecidos a los del lugar, echo "
			       "as� para evitar ojos ajenos al clan.\n");
	
	set_exit_color("cyan_o");
	add_exit("fuera","/w/kryger/workroom.c","standard");
	add_exit("abajo","/w/kryger/clan/control.c","door");
}