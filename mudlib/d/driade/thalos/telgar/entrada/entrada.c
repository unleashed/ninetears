/* By Thalos */

#include "../path.h"

inherit "std/underground";

setup() 
{
        set_exit_color("red");
        set_zone("entrada");
        set_light(20);
        set_short("%^RED%^Entrada a las grutas%^RESET%^");
        set_long("\n%^RED%^Entrada a las grutas%^RESET%^.\n\n" 
	   "La oscuridad reina en esta cueva excavada durante eones por las fuerzas de la naturaleza, la unica luz procede de los musgos y liquenes que cuelgan de las paredes. No parece haber nada peligroso, pero en estas cuevas oscuras nunca se sabe que puedes encontrar en el siguiente recodo del camino""\n\n");
        add_exit("sudeste", ENTRADA+ "ent02.c","standard");
	add_exit("fficmud", "/room/zonas/main","door");        
}