//Ciudad de Faeleen, Flangerant 2002

inherit "/std/ciudad";
#include "../../path.h"

void setup() {
   	set_short("Puerta Norte de la Ciudad de %^BOLD%^Faeleen%^RESET%^.");
   	set_long("Puerta Norte de la Ciudad de %^BOLD%^Faeleen%^RESET%^ \n\n"
            "	Te encuentras en la puerta norte de la ciudad de Faeleen. La puerta en si"
            " es de madera negra y mide mas de cuatro metros de alto. La puerta permanece"
            " abierta la mayor parte del tiempo, demostrando el car�cter abierto de la ciudad"
            " y su bienvenida a quienquiera que lleve los bolsillos llenos.\n"
            "	Enfrente tuyo tienes la majestuosa urbe capital del comercio de todo el "
            "continente. La ciudad de Faeleen se erige siempre orgullosa y rebosante de color,"
            "alumbrados ya por el ardiente sol como por la fria luna.\n\n");
   	set_zone("faeleen_ciudad");
   	add_exit("oeste",CIUDAD"ext_norte_0.c","standard");
   	add_exit("este",CIUDAD"ext_norte_28.c","standard");
   	add_exit("sur",CIUDAD"cnorte_0.c","standard");
	}
