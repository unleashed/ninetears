//Huascar

#include "../path.h"
inherit "/std/outside.c";
void setup()
{
set_short("%^GREEN%^Zona densa%^RESET%^");
set_long("%^GREEN%^Zona densa%^RESET%^\n\n El bosque aqui tremendamente dendo, hasta tal punto que tu "
	 "desorientacion es total. El tupido techo de arboles hace que poca luz "
	 "pueda entrar aqui por lo que es mas bien siniestro. Para colmo de males "
 	 "se oye el poderoso rugido de aterradoras bestias. Lo mas seguro seria salir por "
	 "donde entraste.\n\n");
		
set_light(30);
set_zone("bosque");
add_clone(NPC"osogris.c",random(7)-5);
add_clone(NPC"osonegro.c",random(6)-4);
add_clone(NPC"osopardo.c",random(5)-3);
add_exit("norte",CHA"M15.c","road");
add_exit("noreste",CHA"M16.c","road");
add_exit("este",CHA"M17.c","road");
add_exit("sudeste",CHA"M18.c","road");
add_exit("sur",CHA"M1422.c","road");
add_exit("sudoeste",CHA"M19.c","road");
add_exit("oeste",CHA"M20.c","road");
add_exit("noroeste",CHA"M1.c","road");
}