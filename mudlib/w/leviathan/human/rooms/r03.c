#include "path.h"
inherit HAVMAND+"rock.c";

void setup()
{
    
    set_long("\nIsla de Havmand : Rocas\n\n"
    "  Estas moviendote sobre unas rocas de afiladas aristas. Son muy "
    "deslizadizas, lo cual te obliga a ser muy cauteloso. Hay montones de "
    "pequenyos crustaceos que se aferran firmemente a la roca y prosperan "
    "en esta zona banyada por las mareas altas, y por las olas al romper."
    " Lejos en el mar puedes ver un pequenyo bote de algun tipo, y pajaros "
    "volando en circulo sobre el."
    "\n\n");
    add_item("crustaceos","Mejillones,berberechos y bigaros fuertemente anclados a la "
    "roca.\n");
    add_item("olas","Algunas olas se estrellan con mas fuerza que otras y empapan las rocas "
    "y , si no tienes cuidado tambien a ti.\n");   
    add_item("bote","No puedes verlo claramente, pero te imaginas que es un bote de pesca.\n");
    add_item(({"pajaro","pajaros"}),"Aves marinas sobrevuelan el bote en circulo atentas "
    "a cualquier oportunidad de conseguir comida.\n");

}
void init()
{
    add_exit("este",HAVMAND+"r04.c","path");

    ::init();
}
