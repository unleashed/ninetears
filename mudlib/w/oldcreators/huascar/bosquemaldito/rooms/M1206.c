//Huascar

#include "../path.h"
inherit "/std/outside.c";
void setup()
{
set_short("%^BOLD%^GREEN%^Bosque maldito%^RESET%^");
set_long("%^BOLD%^GREEN%^Bosque maldito%^RESET%^\n\nAnte ti se encuentra el bosque maldito. "
	 "Numerosas leyendas acerca de misteriosas desapariciones en esta zona llegan "
	 "a tu mente. Como en toda historia antigua no sabes que parte puede ser cierta "
 	 "y cual puede ser ficcion pero por si acaso decides mantenerte alerta mientras "
	 "te encuentres por estos parajes.\n\n");
		
set_light(50);
set_zone("maldito");
add_clone(NPC"lobo.c",random(4)-1);
add_clone(NPC"oso.c",random(3)-1);
add_clone(NPC"mapache.c",random(3)-1);
add_exit("oeste",MAL"M1205.c","road");
add_exit("sur",MAL"M1106.c","road");
}
