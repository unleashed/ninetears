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
add_exit("norte",CHA"M7.c","road");
add_exit("noreste",CHA"M8.c","road");
add_exit("este",CHA"M9.c","road");
add_exit("sudeste",CHA"M10.c","road");
add_exit("sur",CHA"M11.c","road");
add_exit("sudoeste",CHA"M12.c","road");
add_exit("oeste",CHA"M13.c","road");
add_exit("noroeste",CHA"M14.c","road");
}