//Gareth 7.12.02

#include "/d/gremios/path.h"
inherit "/std/tienda";

void setup() {
	set_short("%^RED%^%^BOLD%^Gremio de los Khurgars: %^WHITE%^%^BOLD%^Tienda%^RESET%^");
	set_long(query_short()+"\n\n    Una sala rectangular, con un gran mostrador al fondo."
					" Esta es la tienda de Kulthan el Herrero, donde puedes"
					" abastecerte de todo tipo de equipo. Detras del "
					"mostrador se puede ver una forja, donde Kulthan "
					"da forma a todas sus armas. Unas escaleras descienden"
					" hacia la Sala de Trofeos del gremio.\n");
	set_dependiente(NPCS+"kulthan.c");
	
	add_suministro("/baseobs/armaduras/yelmo_grande",1);
	add_suministro("/baseobs/armaduras/guanteletes",5);
	add_suministro("/baseobs/armaduras/cota_reforzada",5);
	add_suministro("/baseobs/armas/hacha_de_batalla",5);
	add_suministro("/baseobs/armas/hacha_a_dos_manos",1);
	add_suministro("/baseobs/escudos/corporal",roll(2,5));
	
	add_ajuste("raza","duergar",75);
	add_prohibido("raza","enano");
	
	add_exit("arriba",GUILD_KHURGARS+"guildroom","corridor");
	add_exit("abajo",GUILD_KHURGARS+"trofeos","corridor");	
	add_cartel("cartel");
}