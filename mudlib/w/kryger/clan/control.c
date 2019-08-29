//Kryger 2003//
inherit "/std/room.c";

void setup()
{
	set_short("%^BOLD%^RED%^Age of %^BLACK%^Darkness: %^RESET%^RED%^Habitacion de Control%^RESET%^");
	set_long(query_short()+"\n\nEntras en las estancias del clan Age of Darkness, es una estancia "
	                       "poco iluminada, apenas iluminada por las multiples antorchas que hay  "
						   "por las paredes. En estas se pueden ver grabados de toda clase, batallas, "
						   "enfrentamientos entre clanes y algunas de los equipos mas utilizados por "
						   "los mas celebres miembros del clan.\n");
	
	
	set_exit_color("cyan_o");
	add_exit("sur","/w/kryger/clan/baul4.c","secret");
	add_exit("norte","/w/kryger/clan/tesoreria.c","standard");
	add_exit("arriba","/w/kryger/clan/entrada.c","door");
}