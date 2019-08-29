//Gareth 7.12.02

#include "/d/gremios/path.h"
inherit "/std/tienda";

void setup() {
	set_short("%^RED%^%^BOLD%^Gremio de los Guerreros Turkhun: %^WHITE%^%^BOLD%^Tienda%^RESET%^");
	set_long(query_short()+"\n\n    Una sala rectangular, con un gran mostrador al fondo."
					" Esta es la tienda de Chilak el Herrero, donde puedes"
					" abastecerte de todo tipo de equipo. Detras del "
					"mostrador se puede ver una forja, donde Chilak "
					"da forma a todas sus armas. Unas escaleras descienden"
					" hacia la Sala de Trofeos del gremio.\n");
	set_dependiente(NPCS+"chilak.c");
	
	add_suministro("/baseobs/armaduras/yelmo_grande",1);
	add_suministro("/baseobs/armaduras/guanteletes",5);
	add_suministro("/baseobs/armaduras/cota_reforzada",5);
	add_suministro("/baseobs/armas/hacha_de_batalla",5);
	add_suministro("/baseobs/armas/hacha_a_dos_manos",1);
	add_suministro("/baseobs/escudos/corporal",roll(2,5));
	
	add_ajuste("raza","humano",75);
	add_prohibido("raza","drow");
	
	add_exit("arriba",GUILD_TURKHUN+"guildroom","corridor");
	add_exit("abajo",GUILD_TURKHUN+"trofeos","corridor");	
	add_cartel("cartel");
}
