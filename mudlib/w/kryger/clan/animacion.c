//Kryger 2003//
inherit "/std/room.c";

void setup()
{
	set_short("%^BOLD%^RED%^Age of %^BLACK%^Darkness: %^RESET%^RED%^Sala de Animacion %^RESET%^");
	set_long(query_short()+"\n\n Llegas a la tesoreria del clan Age of Darkness, aqui es donde "
	                       "sus miembros ingresan el dinero conseguido en batallas, enfrentamientos "
						   "y demas tipo de medios para mantener el clan siempre en buen estado y "
						   "poder remodelarlo a su gusto, la iluminaci�n como en el resto de habitaciones "
						   "es muy leve, pero suficiente para verlo todo.\n");
	
	
	set_exit_color("cyan_o");
	add_exit("sudoeste","/w/kryger/clan/baul1.c","standard");
	add_exit("norte","/w/kryger/clan/raises.c","standard");
	add_exit("sudeste","/w/kryger/clan/tienda.c","standard");
}