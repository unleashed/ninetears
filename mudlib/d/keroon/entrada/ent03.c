/* Thalos */
#include "../path.h"
inherit "/std/suboscuridad";

void setup()
{
  set_short("%^RED%^Entrada a las grutas%^RESET%^");
  set_long("%^RED%^Entrada a las grutas%^RESET%^\n\n" +
	   "La oscuridad reina en esta cueva excavada durante eones por"
	   " las fuerzas de la naturaleza, la unica luz procede de los musgos" +
           " y liquenes que cuelgan de las paredes. No parece haber nada"
           " peligroso, pero en estas cuevas oscuras nunca se sabe que puedes"
           " encontrar en el siguiente recodo del camino.\n\n");

	set_zone("entrada");
        set_light(20);
	set_exit_color("red");

  add_exit("oeste",ENTRADA+"ent02.c","standard");
  add_exit("este",ENTRADA+"ent04.c","standard");
  
}
