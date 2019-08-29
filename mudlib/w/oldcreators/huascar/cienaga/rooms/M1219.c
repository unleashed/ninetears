//Huascar

#include "../path.h"
inherit "/std/outside.c";
void setup()
{
set_short("%^GREEN%^Cienaga%^RESET%^");
set_long("%^GREEN%^Cienaga%^RESET%^\n\nEstas en las humedas tierras de la cienaga. El agua inundo estas tierras "
	 "hace anyos llenando de lodo los restos de la antigua batalla entre las "
	 "mas terribles fuerzas de otros tiempos. Aun asi puedes ver los restos de "
 	 "la misma pues de vez en cuando encuentras esqueletos desmembrados y restos "
	 "de armas oxidadas y en un estado totalmente inservible.\n");
		
    set_light(50);
set_zone("cienaga");
add_clone(NPC"zombieenano.c",random(3)-1);
add_clone(NPC"rata.c",random(3)-1);
add_exit("norte",MAR"M1319.c","road");
add_exit("oeste",MAR"M1218.c","road");
add_exit("sur",MAR"M1119.c","road");
add_exit("este",MAR"M1220.c","road");
}