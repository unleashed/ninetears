//Kryger 2003//
inherit "/std/room.c";

void setup()
{
	set_short("%^BOLD%^RED%^Age of %^BLACK%^Darkness: %^RESET%^RED%^Camara secreta %^RESET%^");
	set_long(query_short()+"\n\n Llegas a la tesoreria del clan Age of Darkness, aqui es donde "
	                       "sus miembros ingresan el dinero conseguido en batallas, enfrentamientos "
						   "y demas tipo de medios para mantener el clan siempre en buen estado y "
						   "poder remodelarlo a su gusto, la iluminaci�n como en el resto de habitaciones "
						   "es muy leve, pero suficiente para verlo todo.\n");
	
	
	set_exit_color("cyan_o");
	add_exit("noreste","/w/kryger/clan/baulm7.c","secret");
	add_exit("noroeste","/w/kryger/clan/baulm3.c","secret");
	add_exit("sudeste","/w/kryger/clan/baulm11.c","secret");
	add_exit("sudoeste","/w/kryger/clan/baulm14.c","secret");
}