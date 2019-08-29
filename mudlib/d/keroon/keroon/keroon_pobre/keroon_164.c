// Made by Thalos  01/04/02

inherit "/std/suboscuridad";
#include "../../path.h"
object guardia1,guardia2;

void setup() {

   set_exit_color("cyan");
   set_light(50);
   set_short("%^BOLD%^BLUE%^Entrada a %^BLACK%^Keroon%^RESET%^");
   set_long("\n%^BOLD%^BLUE%^Entrada a %^BLACK%^Keroon%^RESET%^.\n\n""Te hallas enfrente de las macizas puertas de piedra y metal que custodian la entrada a la ciudad de Keroon, a la vista de estas imponentes puertas te sientes empequenyecidos y comprendes porque se considera inexpugnable la ciudad mientras las puertas no caigan.""\n\n");
add_sign("Un gran signo clavado en la pared.\n"
           "Parece que tiene algo escrito.\n",
           "\t ________________________________________  \n"
           "\t|\\______________________________________/| \n"
           "\t||                                      || \n"
           "\t||          %^BLUE%^CIUDAD DE KEROON%^RESET%^            || \n"
           "\t||                                      || \n"
           "\t||   -- Se prohibe el acceso a la       || \n"
           "\t||      ciudad a las razas indeseable.  || \n"
           "\t||                                      || \n"
           "\t||   -- Cualquiera que ataque a los     || \n"
           "\t||      ciudadanos que se atenga a las  || \n"
           "\t||      consecuencias.                  || \n"
           "\t||                                      || \n"
           "\t||  Firmado Gredfor III                 || \n"
           "\t||______________________________________|| \n"
           "\t|/______________________________________\\| \n\n");

    add_exit("noroeste",CAMINO+"cami_98.c","door");
    add_exit("puertas",KEROONPOBRE+"keroon_165.c","door");
    modify_exit("puertas", ({"function", "go_entrar"}));

}

void reset()
{
	if (!guardia1) {
		guardia1 = clone_object(NPCSKEROONPOBRE +"guardia_puerta.c");
		guardia1->add_property("NO_BUDGE", 1);
		guardia1->move(this_object());
	}
	if (!guardia2) {
		guardia2 = clone_object(NPCSKEROONPOBRE +"guardia_puerta.c");
		guardia2->add_property("NO_BUDGE", 1);
		guardia2->move(this_object());
	}
}

int go_entrar()
    {
    		string *razas_si = ({"duergar","orco","goblin","medio-orco","inmortal"});
    		string mi_raza = TP->query_race();
                if(!guardia1 && !guardia2) {
                	tell_object(TP,"Tienes la via libre para entrar en la ciudad.\n");
                	return 1;
                }                
                if( member_array(mi_raza,razas_si)==-1 ) {
                	tell_object(TP,"Los guardias se interponen en tu camino.\n");
                	tell_room(ENV(TP),"Los guardias se interponen en el camino "
                	"de " +TP->query_cap_name()+".\n" ) ;
         
                	return 0;
                }
               
	tell_object(this_player(), "Un guardia te saluda al entrar en Keroon.\n");
	tell_room(this_object(), this_player()->query_short()+
		" es saludado por un guardia al entrar en Keroon.\n", this_player());
	
	return 1;
}

int go_salir()
{
	return 1;
}
