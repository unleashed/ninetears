//Gareth 6.12.02

#include "/d/gremios/path.h"
inherit "/std/room";
object guardia;

void setup() {
	set_short("%^RED%^%^BOLD%^Gremio de los Guerreros Turkhun: %^WHITE%^%^BOLD%^Entrada%^RESET%^");
	set_long(query_short()+"\n\n    Esta es la entrada al gremio de los Guerreros Turkhun, "
					"donde dos guardias vigilan que nadie que no sea "
					"Duergar pase al gremio. Esta estancia es la primera"
					" de las cavernas del gremio, excavadas en la piedra"
					" por los Duergars. El estandarte de los Guerreros Turkhun"
					" cuelga encima de una doble puerta de hierro.\n");
	
	add_item("estandarte","El estandarte de los Guerreros Turkhun, dos hachas de batalla cruzadas sobre un fondo rojo oscuro.\n");
	add_item("puerta","Una gran puerta doble de hierro, vigilada por dos guardias duergars.\n");
	
	(guardia=clone_object(NPCS+"guardia_turkhun.c"))->move(TO);
	(guardia=clone_object(NPCS+"guardia_turkhun.c"))->move(TO);
	
	add_exit("dentro",GUILD_TURKHUN+"guildroom","door");
	modify_exit("dentro",({"function","entrar"}));
	add_exit("fuera","/room/plaza/campo_discordia_3","plain");
}


void init() {
	::init(); 
	}

int entrar() {
	if (TP->query_creator()) return 1;
	if (TP->query_race()=="humano") if(TP->query_guild()=="turkhun"||!TP->query_guild_ob()) return 1;
        if (!guardia) {
                tell_object(TP,"Te aprovechas de que no hay Guardias para colarte en el gremio.\n");
                return 1;
        	}
	return notify_fail("Los Guardias te impiden el paso.\n");
	}
