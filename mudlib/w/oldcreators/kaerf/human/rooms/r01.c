#include "path.h"
inherit HAVMAND+"rock.c";

void setup()
{
    
    set_long("\nIsla de Havmand : Rocas\n\n"
    "   Estas moviendote sobre unas rocas de afiladas aristas. Son muy "
    "deslizadizas, lo cual te obliga a ser muy cauteloso. Hay montones de "
    "pequenyos crustaceos que se aferran firmemente a la roca y prosperan "
    "en esta zona banyada por las mareas altas, y por las olas al romper."
    "\n\n");
    add_item("crustaceos","Mejillones,berberechos y bigaros fuertemente anclados a la "
    "roca.\n");
    add_item("olas","Algunas olas se estrellan con mas fuerza que otras y empapan las rocas "
    "y , si no tienes cuidado tambien a ti.\n");

}
void init()
{
    add_exit("este",HAVMAND+"r02.c","path");

    ::init();
}
